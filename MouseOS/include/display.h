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

/**
 * Basic display functions. They use indirect writes to the video frame buffer.
 * Only text mode 7 is supported for now
 */
#ifndef DISPLAY_H_
#define DISPLAY_H_

/**
 * We are in Mode 7 at startup
 */
#define COLUMNS 80
#define ROWS 25
/**
 * Color monitor frame buffer
 * @todo add other options
 */
#define VIDEO_MEMORY_COLOR 0xB8000

/**
 * Commands for accessing cursor locations in CRT controller.
 */
#define CURSOR_LOCATION_HIGH 0x0e
#define CURSOR_LOCATION_LOW 0x0f

/**
 * CRT controller ports
 * @todo add all controller commands and ports
 */
#define DISPLAY_CONTROL_PORT 0x03d4
#define DISPLAY_DATA_PORT 0x03d5

/**
 * Tabulator length in characters
 */
#define TAB_LENGTH 8

void display_char(char c);
void display_string (char* s);
void clear_screen();

#endif /* DISPLAY_H_ */
