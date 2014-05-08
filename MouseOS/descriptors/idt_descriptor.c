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

#include <idt_descriptor.h>
#include <stdio.h>
#include <processor_interrupts.h>

#define GDT_CODE_DESCRIPTOR 0x08
/**
 * Load the IDTR register.
 */
static void load_idtr();
static void idt_add_descriptor(u08 number,u16 selector,u08 flags,u32 base);
/**
 * This is our common isr for every interrupt until we implement
 * them individually.
 */
//static void isr_common();

/**
 * Value of IDTR
 */
static idtr idtr_val;
/**
 * The descriptors
 */
static idt_descriptor idt_descriptors[MAX_IDT_DESCRIPTORS];

/**
 * Pointers to ISR functions
 */
static void (*isr_pointers[MAX_IDT_DESCRIPTORS])(void);

void idt_init_descriptors() {


	idtr_val.limit=(sizeof (idt_descriptor)*MAX_IDT_DESCRIPTORS)-1;
	// 32bit address of descriptor table
	idtr_val.base=(u32)idt_descriptors;

	// has to be zeroed (actually only present flag should be zero
	// but why bother)
	memset((char*)idt_descriptors,sizeof (idt_descriptor)*MAX_IDT_DESCRIPTORS,0);

	//int i;
	// 32 reserved processor interrupts and exceptions
	//for (i=0;i<32;i++) {
	//	idt_register_isr(i,isr_common);
	//}

	// register the 32 processor interrupts and exceptions
	processor_interrupts_init();
	// load the idtr
	load_idtr();
}
/**
 * Register a custom ISR for a given IRQ
 */
void idt_register_isr(int number,void (*new_isr)(void)) {

	//if the number is too high, return
	if (number>256) {
		return;
	}
	// assign the new isr to the table
	isr_pointers[number]=new_isr;
	//@todo  explain the flags
	idt_add_descriptor(number, GDT_CODE_DESCRIPTOR,
					IDT_PRESENT|IDT_RING0|IDT_INTERRUPT_GATE,(u32) isr_pointers[number]);

}
/**
 * This is our common isr for every interrupt until we implement
 * them individually.
 */
/**static void isr_common() {
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	asm("movl %ebp,%esp");
	asm ("pop %ebp");
	// and return from interrupt
	asm("iret");

}*/

/**
 * Load the idtr
 */
static void load_idtr() {
	__asm__ ("lidt (idtr_val)");
}
/**
 * Add a descriptor
 */
static void idt_add_descriptor(u08 number,u16 selector,u08 flags,u32 base) {

	//just add the fields
	idt_descriptors[number].base_low=(u16)base;
	idt_descriptors[number].base_high=(u16)(base>>16);
	idt_descriptors[number].flags=flags;
	idt_descriptors[number].reserved=0;
	idt_descriptors[number].selector=selector;

}

