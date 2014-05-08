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
 * This file creates and manages Global Descriptor Tables (segmentation)
 * in Protected Mode.
 */
#ifndef GDT_DESCRIPTOR_H_
#define GDT_DESCRIPTOR_H_

#include <types.h>

struct _gdt_descriptor {
	u16 limit;
	u16 base_low;
	u08 base_middle;
	u16 flags;
	u08 base_high;
}__attribute__((packed)); // the fields are word aligned by default, so we need to add this

typedef struct _gdt_descriptor gdt_descriptor, * pgdt_descriptor ;

struct _gdtr {
	u16 limit;
	u32 base;
} __attribute__((packed));

typedef struct _gdtr gdtr;


/**
 * flags and masks for GDT
 * @todo explain these flags
 */
#define GDT_GRANLUARITY_4K 0x8000
#define GDT_SEGMENT_32BIT 0x4000
#define GDT_SEGMENT_LIMIT 8 // no. of bits for shift
#define GDT_IN_MEMORY 0x0080
#define GDT_PRIVILEGE_MASK 0x0060
#define GDT_RING0 0x0000
#define GDT_RING1 0x0002
#define GDT_RING2 0x0040
#define GDT_RING3 0x0060
#define GDT_CODE_OR_DATA 0x0010
#define GDT_CODE 0x0008
#define GDT_EXPANSION 0x0004 // check what it does!!!
#define GDT_WRITEABLE_EXECUTABLE 0x0002
#define GDT_ACCESS 0x0001

/**
 * Maximum number of descriptors we want
 */
#define MAX_GDT_DESCRIPTORS 10

void gdt_init_descriptors();



#endif /* GDT_DESCRIPTOR_H_ */
