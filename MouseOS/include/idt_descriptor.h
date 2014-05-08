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
 * This file creates and manages Interrupt Descriptor Tables
 * and Interrupt Vectors in Protected Mode.
 */

#ifndef IDT_DESCRIPTOR_H_
#define IDT_DESCRIPTOR_H_

#include <types.h>



/**
 * Interrupt descriptor
 */
struct _idt_descriptor {
	u16 base_low;
	u16 selector;
	u08 reserved;
	u08 flags;
	u16 base_high;
}__attribute__((packed));

typedef struct _idt_descriptor idt_descriptor;

/**
 * Value of the IDT register
 */
struct _idtr {
	u16 limit;
	u32 base;
} __attribute__((packed));

typedef struct _idtr idtr;

/**
 * flag definitions @todo explain these flags
 */
#define IDT_PRESENT 0x80
#define IDT_PRIVILEGE_MASK 0x60
#define IDT_RING0 0x00
#define IDT_RING1 0x20
#define IDT_RING2 0x40
#define IDT_RING3 0x60
#define IDT_TYPE_MASK 0x1f
#define IDT_INTERRUPT_GATE 0b01110
#define IDT_TASK_GATE 0b00101
#define IDT_TRAP_GATE 0b01111

/**
 * There can be only 256 interrupts.
 */
#define MAX_IDT_DESCRIPTORS 256

/**
 * Initialize the IDT (32 processor interrupts, from 0x0 to 0x1f)
 */
void idt_init_descriptors();
/**
 * Function for registering more descriptors.
 * Just specify the number of the interrupt and
 * a function pointer to the Interrupt Service Routine (ISR).
 */
void idt_register_isr(int number,void (*new_isr)(void));


#endif /* IDT_DESCRIPTOR_H_ */
