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
 * Driver for the programmable interval timer - Intel 8253 or 8254.
 * See Intel datasheet for details.
 */
#ifndef PIT_H_
#define PIT_H_

/**
 * We need this for the ISR number
 */
#include <dev/pic.h>
#include <types.h>

/**
 * Address lines of the PIT
 */
#define PIT_A0 0
#define PIT_A1 1
/**
 * Base IO address for PIT in PC compatibles
 */
#define PIT_BASE_IO_ADDRESS 0x40
/**
 * I/O ports for the PIT - defined by the two address lines
 */
#define PIT_COUNTER0 ( PIT_BASE_IO_ADDRESS|(0<<PIT_A0)|(0<<PIT_A1) ) //a1a0=0b00
#define PIT_COUNTER1 ( PIT_BASE_IO_ADDRESS|(1<<PIT_A0)|(0<<PIT_A1) ) //a1a0=0b01
#define PIT_COUNTER2 ( PIT_BASE_IO_ADDRESS|(0<<PIT_A0)|(1<<PIT_A1) ) //a1a0=0b10
#define PIT_CONTROL  ( PIT_BASE_IO_ADDRESS|(1<<PIT_A0)|(1<<PIT_A1) ) //a1a0=0b11

/**
 * PIT is on line IR0 of the first PIC
 */
#define PIT_ISR (PIC1_BASE+PIC_IR0)

/**
 * Control word format ***************************************
 *
 * Count format bit
 * 1-BCD counter,4 decades; 0-binary counter, 16 bits
 */
#define PIT_BCD 0
/**
 * Mode bits
 * M2M1M0=0b000 mode 0
 * 001 mode1
 * x10 mode2
 * x11 mode3
 * 100 mode4
 * 101 mode5
 */
#define PIT_M0 1
#define PIT_M1 2
#define PIT_M2 3
#define PIT_MODE_MASK 0x0e // mask for the timer's mode
/**
 * RW1RW0=0b00- counter latch command
 * 01- read/write least significant byte only
 * 10- read/write most significant byte only
 * 11- read/write LSB first and then MSB
 */
#define PIT_RW0 4
#define PIT_RW1 5
#define PIT_RW_MASK 0x30 // mask for RW bits
/**
 * 00 select counter 0
 * 01 select counter 1
 * 10 select counter 2
 * 11 read-back command
 */
#define PIT_SC0 6
#define PIT_SC1 7
#define PIT_COUNTER_MASK 0xc0 // mask for counter number

/**
 * PIT status byte (returned for read-back command)
 * 6 LSB are the same as for control word
 *
 * 1 null count
 * 0 count available for reading
 */
#define PIT_NULL_COUNT 6
/**
 * Value on counter's OUT line
 */
#define PIT_OUTPUT 7

/**
 * PIT modes *****************************************************
 */
#define PIT_MODE0 ( (0<<PIT_M2)|(0<<PIT_M1)|(0<<PIT_M0) ) // interrupt on terminal count
#define PIT_MODE1 ( (0<<PIT_M2)|(0<<PIT_M1)|(1<<PIT_M0) ) // hardware retriggerable one-shot
#define PIT_MODE2 ( (0<<PIT_M2)|(1<<PIT_M1)|(0<<PIT_M0) ) // rate generator
#define PIT_MODE3 ( (0<<PIT_M2)|(1<<PIT_M1)|(1<<PIT_M0) ) // square wave mode
#define PIT_MODE4 ( (1<<PIT_M2)|(0<<PIT_M1)|(0<<PIT_M0) ) // software triggered strobe
#define PIT_MODE5 ( (1<<PIT_M2)|(0<<PIT_M1)|(1<<PIT_M0) ) // hardware triggered strobe

/**
 * Read back command format **************************************
 *
 * Bit 0 is always 0. So we ignore it.
 * Counter bits - 1 means the given counter is selected
 */
#define PIT_CNT0 	1
#define PIT_CNT1 	2
#define PIT_CNT2 	3
#define PIT_STATUS	4 // 0-read status byte; 1-don't read status
#define PIT_COUNT	5 // 0-read counter value; 1-don't read value
// bits 6 and 7 are the same as for control word (0b11 for read-back command)

/**
 * Base frequency for PIT in PC
 */
#define PIT_FREQUENCY 1193182
/**
 * PIT counts down from initial value to zero.
 * So frequency is PIT_FREQUENCY/PIT_INITIAL_COUNT.
 * This actually calculates the interrupt frequency only
 * for mode 2 and 3
 */
#define PIT_INITIAL_COUNT(frequency) (PIT_FREQUENCY/frequency)

/**
 * Time passed since turning PIT on.
 */
extern volatile int pit_seconds;
extern volatile int pit_minutes;
extern volatile int pit_hours;


/**
 * Initialize PIT at a given frequency of interrupts.
 */
void pit_init(int frequency);
/**
 * Read status bytes of the PITs
 */
void pit_read_status ();

u16 pit_counter_latch (int counter);

#endif /* PIT_H_ */
