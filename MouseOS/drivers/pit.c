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

#include <dev/pit.h>
#include <idt_descriptor.h>
#include <stdio.h>
#include <ports.h>

/**
 * Tick counter
 */
static int pic_counter;
/**
 * Time passed since turning PIT on.
 */
volatile int pit_seconds;
volatile int pit_minutes;
volatile int pit_hours;
/**
 * Frequency assigned to the PIC
 */
static int pit_frequency;

/**
 * PIT counters' status bytes.
 */
static u08 pit_status_bytes[3];

static inline void pit_send_command(int command);
static inline void pit_send_data(int data, int counter);
static void pit_isr();




/**
 * Initialize the PIT
 * @param frequency The frequency of interrupts
 */
void pit_init(int frequency) {

	pit_frequency=frequency;
	// register our isr
	idt_register_isr(PIT_ISR,pit_isr);

	u16 count=(u16)PIT_INITIAL_COUNT(frequency);

	// send lsb first then msb to counter 0
	// out pin of counter 0 is actually connected to IRO of PIC1
	// mode 3 (square wave) - good for edge interrupts
	// binary counter 16 bit
	pit_send_command((1<<PIT_RW0)|(1<<PIT_RW1)|PIT_MODE3|(0<<PIT_SC0)|(0<<PIT_SC1)|(0<<PIT_BCD));
	// send the initial count value
	pit_send_data((u08)count,PIT_COUNTER0);
	pit_send_data((u08)(count>>8),PIT_COUNTER0);

}

/**
 * Read status or counter value through read back command.
 * For now we just read counter 0 - only one used.
 *
 */
void pit_read_status () {
	// read-back command has SC1SC0=11
	// we want to read status not counter values
	// we read only counter 0
	port_out(PIT_CONTROL,(u08) (3 << PIT_SC0)|(0<<PIT_STATUS)|(1<<PIT_COUNT)|(1<<PIT_CNT0) );
	pit_status_bytes[0]=port_in(PIT_COUNTER0);
	puts("Status byte for counter 0 is ");
	println(itoa16(pit_status_bytes[0]));
}

/**
 * Read the counter value through counter latch command.
 */
inline u16 pit_counter_latch (int counter) {
	// format of this command is SC1SC0=counter, RW1RW0=00, and rest unused (zero)
	port_out(PIT_CONTROL,(u08)(counter << PIT_SC0)|(0<<PIT_RW0)|(0<<PIT_RW1) );

	u16 ret=port_in(PIT_BASE_IO_ADDRESS+counter);
	ret|=(port_in(PIT_BASE_IO_ADDRESS+counter)<<8);

	return ret;
}

/**
 * The ISR for out PIT- we can use it to measure time.
 */
static void pit_isr() {
	// c does this:
	// push %ebp
	//mov %esp,%ebp

	// update the time variables

	// you have to count 'frequency' times to get one second
	if (pic_counter++==pit_frequency) {
		pic_counter=0;
		pit_seconds++;
		//puts("Another second has passed: ");
		//println(itoa(pit_seconds));

		if (pit_seconds==60) {
			pit_seconds=0;
			pit_minutes++;
			puts("Another minute has passed: ");
			println(itoa(pit_minutes));

			if(pit_minutes==60) {
				pit_minutes=0;
				pit_hours++;
			}
		}
	}

	// we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}


/**
 * Send command to the PIT
 */
static inline void pit_send_command(int command) {
	port_out(PIT_CONTROL,(u08)command);
}
/**
 * Send data to the PIT. You must specify the address of the counter.
 */
static inline void pit_send_data(int data, int counter) {
	port_out((u16)counter,(u08)data);
}


