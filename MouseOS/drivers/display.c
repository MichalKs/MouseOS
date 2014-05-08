/**
 * @file:
 * @brief:
 * @date: 	9 kwi 2014
 * @author: Michal Ksiezopolski
 *
 *
 * @verbatim
 * Copyright (c) 2014 Michal Ksiezopolski.
 * All rights reserved. This program and the
 * accompanying materials are made available
 * under the terms of the GNU Public License
 * v3.0 which accompanies this distribution,
 * and is available at
 * http://www.gnu.org/licenses/gpl.html
 * @endverbatim
 */


#include <display.h>
#include <types.h>
#include <bios_attributes.h>
#include <ports.h>



/**
 * Current row
 */
static u08 x = 0;
/**
 * Current column
 */
static u08 y = 0;
/**
 * Attribute byte - color of text and background of empty space
 */
static u08 empty_screen_attribute=(CYAN << 4) | (WHITE);
/**
 * Attribute byte - text and background color for characters
 */
static u08 character_attribute=	(BLUE << 4) | (WHITE);

/**
 * Internal function for moving the cursor - the position is set earlier by other functions.
 */
static void move_cursor()
{
    u16 new_position = y * COLUMNS + x;
    // command for sending high byte of cursor location
    port_out(DISPLAY_CONTROL_PORT, CURSOR_LOCATION_HIGH);
    // we send the high byte
    port_out(DISPLAY_DATA_PORT, new_position >> 8);
    // command for sending low byte of cursor location
    port_out(DISPLAY_CONTROL_PORT, CURSOR_LOCATION_LOW);
    // we send the low byte
    port_out(DISPLAY_DATA_PORT, new_position);
}

/**
 * Internal function for scrolling the display after writing to it.
 */
static void scroll_display()
{
    // space character for filling up the scrolled line
    // every character is two bytes - one for character and one for attribute
    u16 space = ' ' | (empty_screen_attribute << 8);

    // scroll if too many rows
    if(y >= ROWS)
    {
    	// pointer to video memory
    	u16* ptr = (u16*) VIDEO_MEMORY_COLOR;
        int i;
        // copy all data one row (columns size characters) up
        for (i = 0; i < (ROWS-1)*COLUMNS; i++)
        {
        	// next line is columns size characters less
        	ptr[i] = ptr[i+COLUMNS];
        }
        // insert row of spaces on last row
        for (i = (ROWS-1)*COLUMNS; i < ROWS*COLUMNS; i++)
        {
        	ptr[i] = space;
        }
        // row equals last row (rows are counted from zero)
        y = ROWS-1;
    }
}

/**
 * Display a character on screen.
 */
void display_char(char c)
{
    // if tab pressed
    if (c == '\t')
    {
    	// Tab is TAB_LENGTH chars long by default but is aligned to TAB_LENGTH chars also
    	// For example, for TAB_LEGTH=8, this cuts out three least significant bits of x
    	// making x aligned to 8 characters
        x = (x+TAB_LENGTH) & ~(TAB_LENGTH-1);
    }
    // if carriage return
    else if (c == '\r')
    {
    	// shift to first column
        x = 0;
    }
    // if line feed
    else if (c == '\n')
    {
    	// we treat the '\n' character as a CR LF sequence
    	// carriage return
        x = 0;
        // line feed
        y++;
    }
    // if not special character
    else
    {
    	// write the char
    	u16* ptr = (u16*) VIDEO_MEMORY_COLOR;
        ptr += y*COLUMNS + x;
        *ptr = (u16) c | character_attribute<<8;
        // move column
        x++;
    }
    // if character number equals COLUMN length - new line
    if (x >= COLUMNS)
    {
    	//CR
        x = 0;
        //LF
        y ++;
    }

    // make necessary changes - scroll display and move cursor
    scroll_display();
    move_cursor();

}

/**
 * Clear entire screen.
 */
void clear_screen()
{

    u16 space = ' ' | (empty_screen_attribute << 8);

    u16* ptr=(u16*)VIDEO_MEMORY_COLOR;
    int i;
    // fill screen with spaces
    for (i = 0; i < COLUMNS*ROWS; i++)
    {
    	ptr[i] = space;
    }
    // initial position
    x = 0;
    y = 0;
    move_cursor();
}

/**
 * Display a string.
 */
void display_string(char *s)
{
    int i = 0;
    while (s[i])
    {
        display_char(s[i++]);
    }
}
