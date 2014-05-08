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

#include <processor_interrupts.h>
#include <stdio.h>
#include <idt_descriptor.h>


static void isr0();
static void isr1();
static void isr2();
static void isr3();
static void isr4();
static void isr5();
static void isr6();
static void isr7();
static void isr8();
static void isr9();
static void isr10();
static void isr11();
static void isr12();
static void isr13();
static void isr14();
static void isr15();
static void isr16();
static void isr17();
static void isr18();
static void isr19();
static void isr20();
static void isr21();
static void isr22();
static void isr23();
static void isr24();
static void isr25();
static void isr26();
static void isr27();
static void isr28();
static void isr29();
static void isr30();
static void isr31();

//@todo describe every interrupt

void processor_interrupts_init(){
	idt_register_isr(0,isr0);
	idt_register_isr(1,isr1);
	idt_register_isr(2,isr2);
	idt_register_isr(3,isr3);
	idt_register_isr(4,isr4);
	idt_register_isr(5,isr5);
	idt_register_isr(6,isr6);
	idt_register_isr(7,isr7);
	idt_register_isr(8,isr8);
	idt_register_isr(9,isr9);
	idt_register_isr(10,isr10);
	idt_register_isr(11,isr11);
	idt_register_isr(12,isr12);
	idt_register_isr(13,isr13);
	idt_register_isr(14,isr14);
	idt_register_isr(15,isr15);
	idt_register_isr(16,isr16);
	idt_register_isr(17,isr17);
	idt_register_isr(18,isr18);
	idt_register_isr(19,isr19);
	idt_register_isr(20,isr20);
	idt_register_isr(21,isr21);
	idt_register_isr(22,isr22);
	idt_register_isr(23,isr23);
	idt_register_isr(24,isr24);
	idt_register_isr(25,isr25);
	idt_register_isr(26,isr26);
	idt_register_isr(27,isr27);
	idt_register_isr(28,isr28);
	idt_register_isr(29,isr29);
	idt_register_isr(30,isr30);
	idt_register_isr(31,isr31);

}

void isr0(){
	// c does this automatically:
	// push %ebp
	// mov %esp,%ebp

	println("We are inside interrupt 0!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}

void isr1(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside interrupt 1!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr2(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside  interrupt 2!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr3(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 3!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr4(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 4!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr5(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 5!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}

void isr6(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 6!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}

void isr7(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 7!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr8(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 8!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr9(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 9!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr10(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 10!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr11(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 11 !!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr12(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 12!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr13(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 13!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr14(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 14!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr15(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 15!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr16(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 16!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr17(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 17!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr18(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 18!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr19(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 19!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr20(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 20!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr21(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 21!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr22(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 22!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr23(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 23!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr24(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 24!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr25(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 25!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr26(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 26!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr27(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 27!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr28(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 28!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr29(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 29!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr30(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 30!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
void isr31(){
	// c does this automatically:
	// push %ebp
	//mov %esp,%ebp

	println("We are inside a default interrupt 31!!!!!");
	println("Halting system!!!!!");
	for (;;) {

	}
	// so we have to pop ebp,etc.
	__asm__("movl %ebp,%esp");
	__asm__ ("pop %ebp");
	// and return from interrupt
	__asm__("iret");
}
