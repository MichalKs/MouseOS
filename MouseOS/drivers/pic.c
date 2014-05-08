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

#include <dev/pic.h>
#include <ports.h>

/**
 * Use PIC1 or PIC2 for PIC numbers
 */
/**
 * Send command to PIC
 */
static void pic_send_command(pic_number pic,int command);
/**
 * Send data to PIC
 */
static void pic_send_data(pic_number pic,int data);
/**
 * Initialize the PICS
 * Base addresses are passed as arguments.
 *
 */
void pic_init(int pic1_base, int pic2_base) {

	// icw4 needed, cascade mode, edge triggered
	u08 icw=(1<<PIC_ICW1_ALWAYS_ONE)|(1<<PIC_ICW1_IC4);

	//send icw1 - only icw1 is sent as command
	pic_send_command(PIC1,icw);
	pic_send_command(PIC2,icw);

	// send base vector addresses, icw2
	pic_send_data(PIC1,pic1_base&PIC_ICW2_INT_BASE_MASK);
	pic_send_data(PIC2,pic2_base&PIC_ICW2_INT_BASE_MASK);

	// send icw3 to pic1
	pic_send_data(PIC1, (1<<PIC_SLAVE_IR));

	// icw4 - x86 mode, auto end of interrupt, nonbuffered mode
	// not special fully nested mode
	icw=(1<<PIC_ICW4_UPM)|(1<<PIC_ICW4_AEOI);
	pic_send_data(PIC1,icw);
	pic_send_data(PIC2,icw);

}
/**
 * Send command to PIC
 */
void pic_send_command(pic_number pic,int command) {

	// wrong pic
	if (pic!=PIC1 && pic!=PIC2) {
		return;
	}

	u16 port= (pic==PIC1)? PIC1_COMMAND:PIC2_COMMAND;

	port_out(port,(u08)command);

}
/**
 * Send data to PIC
 */
static void pic_send_data(pic_number pic,int data) {

	// wrong pic
	if (pic!=PIC1 && pic!=PIC2) {
		return;
	}

	u16 port= (pic==PIC1)? PIC1_DATA:PIC2_DATA;

	port_out(port,(u08)data);

}

