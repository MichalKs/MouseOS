/**
 * @file: 	main.c
 * @brief:	Testing a simple OS kernel for x86.
 * @date: 	18 sie 2014
 * @author: Michal Ksiezopolski
 *
 * The kernel was tested and therefore
 * should work on Virtualbox, QEMU and
 * real PCs with floppy disks.
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

#include <stdio.h>
#include <string.h>
#include <gdt_descriptor.h>
#include <idt_descriptor.h>
#include <dev/pic.h>
#include <dev/pit.h>
#include <dev/keyboard.h>
#include <dev/pci.h>

/**
 * Variable for easier inline assembly
 */
int temp;

/**
 * Example of a software interrupt
 */
void int57();

int main () {

	// clear the screen
	cls();

	__asm__("mov %ds,temp");
	puts("data segment wskazuje na ");
	println(itoa(temp));

	__asm__("mov %cs,temp");
	puts("code segment wskazuje na ");
	println(itoa(temp));

	// initalize the gdt
	gdt_init_descriptors();
	println("GDT zaladowane.");

	__asm__("mov %ds,temp");
	puts("data segment teraz wskazuje na ");
	println(itoa(temp));

	__asm__("mov %cs,temp");
	puts("code segment teraz wskazuje na ");
	println(itoa(temp));

	// initialize the idt
	idt_init_descriptors();
	// register software interrupt
	idt_register_isr(0x57,int57);
	//trigger sofware interrupt
	__asm__("int $0x57");

	// initialize the PIC and the PIT
	pic_init(PIC1_BASE,PIC2_BASE);
	// 50 Hz tick
	pit_init(50);
	pit_read_status();
	puts("Counter 0 value");
	temp=pit_counter_latch(0);
	println(itoa(temp));

	keyboard_init();



	// dump BIOS data area
	memset((char*)0x150000,256,0xff);
	hexdump((char*)0x400,256);
	int* wsk=&temp;
	puthex((int)wsk);
	//enable interrupts
	__asm__("sti");
	//asm("hlt");
	// infinite loop

	pit_read_status();
	puts("Counter 0 value");
	temp=pit_counter_latch(0);
	println(itoa(temp));

//	pci_discover();
//	println(itoa16(0xffab));
	__asm__("sti");
	for (;;) {
		//putc('*');
	}

	return 0;
}

void int57() {
	// c does this:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside interrupt 57!!!!!");

	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}




