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

#include <gdt_descriptor.h>
/**
 * gdtr register value
 *
 */
static gdtr gdtr_val;
/**
 * Our descriptors
 */
static gdt_descriptor gdt_descriptors[MAX_GDT_DESCRIPTORS];
/**
 * Add a descriptor
 */
static void gdt_add_descriptor(int i, u16 limit, u32 base, u16 flags);
/**
 * Load the GDTR register
 */
static void load_gdtr();
/**
 * Initialize the descriptors
 */
void gdt_init_descriptors() {

	gdtr_val.limit=(sizeof (gdt_descriptor)*MAX_GDT_DESCRIPTORS)-1;
	//32 bit address of the descriptor table
	gdtr_val.base=(u32)gdt_descriptors;

	// null descriptor - needed for some reasons
	gdt_add_descriptor(0,0,0,0);

	/**
	 * Kernel mode code descriptor
	 * @todo explain the flags used for every descriptor
	 */
	gdt_add_descriptor(1,0xffff,0,GDT_GRANLUARITY_4K | GDT_SEGMENT_32BIT |
			(0xf<<GDT_SEGMENT_LIMIT) | GDT_IN_MEMORY | GDT_RING0 | GDT_CODE_OR_DATA |
			GDT_CODE | GDT_WRITEABLE_EXECUTABLE);
	// kernel mode data descriptor
	gdt_add_descriptor(2,0xffff,0,GDT_GRANLUARITY_4K | GDT_SEGMENT_32BIT |
				(0xf<<GDT_SEGMENT_LIMIT) | GDT_IN_MEMORY | GDT_RING0 | GDT_CODE_OR_DATA |
				GDT_WRITEABLE_EXECUTABLE);
	// user mode code descriptor
	gdt_add_descriptor(3,0xffff,0,GDT_GRANLUARITY_4K | GDT_SEGMENT_32BIT |
				(0xf<<GDT_SEGMENT_LIMIT) | GDT_IN_MEMORY | GDT_RING3 | GDT_CODE_OR_DATA |
				GDT_CODE | GDT_WRITEABLE_EXECUTABLE);
	// user mode data descriptor
	gdt_add_descriptor(4,0xffff,0,GDT_GRANLUARITY_4K | GDT_SEGMENT_32BIT |
					(0xf<<GDT_SEGMENT_LIMIT) | GDT_IN_MEMORY | GDT_RING3 | GDT_CODE_OR_DATA |
					GDT_WRITEABLE_EXECUTABLE);

	// load the gdtr - we use our table
	load_gdtr();

}
/**
 * @param i is the descriptor number
 *
 */
static void gdt_add_descriptor(int i, u16 limit, u32 base, u16 flags) {

	// check if i isn't too high
	if (i>MAX_GDT_DESCRIPTORS) {
		return;
	}
	//simply fill in the fields
	gdt_descriptors[i].base_low=base & 0xffff;
	gdt_descriptors[i].base_middle=(base >> 16);
	gdt_descriptors[i].base_low=(base >> 24);
	gdt_descriptors[i].limit=limit;
	gdt_descriptors[i].flags=flags;

}
/**
 * Loads the gdtr register
 */
static void load_gdtr() {

	// load new value to gdtr
	__asm__ ("lgdt (gdtr_val)");
	// we save all registers
	// @todo use inline assembly for telling comiler which registers change
	__asm__("pusha");

	// update data segments - data segment is 0x10
	__asm__ ("movw $0x10,%ax");
	__asm__ ("movw %ax,%ds");
	__asm__ ("movw %ax,%es");
	__asm__ ("movw %ax,%fs");
	__asm__ ("movw %ax,%gs");
	__asm__ ("movw %ax,%ss");

	// indirectly update code segment (0x08)
	__asm__("ljmp $0x08,$label");
	__asm__("label:");

	__asm__("popa");
}


