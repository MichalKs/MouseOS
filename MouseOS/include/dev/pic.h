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
 * This is the driver for the Programmable Interrupt Controller
 * For more info see the datasheet for the Intel 8259A.
 *
 */
#ifndef PIC_H_
#define PIC_H_

/**
 * The number of the PIC
 */
typedef enum _pic_number {PIC1=1,PIC2=2} pic_number;
/**
 * IR lines of a PIC
 */
#define PIC_IR0 0
#define PIC_IR1 1
#define PIC_IR2 2
#define PIC_IR3 3
#define PIC_IR4 4
#define PIC_IR5 5
#define PIC_IR6 6
#define PIC_IR7 7


/**
 * I/O ports for PC
 * Only one address line A0
 */
#define PIC1_COMMAND 0x20
#define PIC1_DATA 0x21
#define PIC2_COMMAND 0xa0
#define PIC2_DATA 0xa1

/**
 * Base addresses for PIC vectors
 * We choose right after the 32 interrupts reserved by the processor
 * i.e. from interrupt vector 32 to 47
 */
#define PIC1_BASE 0x20
#define PIC2_BASE 0x28
/**
 * Slave PIC is connected to IR2 on PC
 */
#define PIC_SLAVE_IR PIC_IR2

/**
 * Bits for Initialization Command 1 (ICW1), A0=0
 */
#define PIC_ICW1_IC4 		0	// 1- ICW4 needed; 0- ICW4 not needed
#define PIC_ICW1_SNGL 		1 	// 1- single PIC; 0- cascade mode
#define PIC_ICW1_ADI 		2 	// 1- call address interval of 4; 0- interval of 8 (only for 8080/85)
#define PIC_ICW1_LTIM 		3 	// 1- level triggered mode; 0= edge triggered mode
#define PIC_ICW1_ALWAYS_ONE 4 	// always one
// we don't use these 3 bits (they're for MCS-80/85 only)
#define PIC_ICW1_A5 		5
#define PIC_ICW1_A6			6
#define PIC_ICW1_A7			7

/**
 * ICW2 in x86 is used for defining bits 7-3 of the interrupt vector number
 * A0=1
 */
#define PIC_ICW2_INT_BASE_MASK 0xf8
/**
 * ICW3 is used for specifying IR that have a slave attached
 * A0=1
 * Each bit corresponds to each IR line
 *
 * For a slave it assigns a slave ID on 3 LSB
 */
#define PIC_ICW3_SLAVE_ID_MASK 0x07

/**
 * ICW4
 * A0=1
 */
#define PIC_ICW4_UPM 	0 // 1- 8086/8088 mode; 0- MCS-80/85 mode
#define PIC_ICW4_AEOI 	1 // 1- auto end of interrupt; 0- normal EOI
/**
 * BUF=0 MS=x non buffered mode
 * BUF=1 MS=0 buffered mode slave
 * BUF=1 MS=1 buffered mode master
 */
#define PIC_ICW4_MS 	2
#define PIC_ICW4_BUF 	3
#define PIC_ICW4_SFNM 	4 // 1- special fully nested mode; 0-not special fully nested mode

/**
 * OCW2 (Operation Command Word 2)
 */
#define PIC_OCW2_L0 0x01
#define PIC_OCW2_L1 0x02
#define PIC_OCW2_L2 0x04
#define PIC_OCW2_EOI 0x20
#define PIC_OCW2_SL 0x40
#define PIC_OCW2_R 0x80

/**
 * OCW 3
 */
#define PIC_OCW3_RIS 0x01
#define PIC_OCW3_RR 0x02
#define PIC_OCW3_P 0x04
#define PIC_OCW3_SMM 0x20
#define PIC_OCW3_ESMM 0x40
// bit 3 must be one
#define PIC_OCW3_BASE 0x08

/**
 * Initialize PICs - we have two
 */
void pic_init(int pic1_base, int pic2_base);




#endif /* PIC_H_ */
