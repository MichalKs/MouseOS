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
 * Functions for low level IO access.
 */
#include <ports.h>

/**
 * Outputs a byte to IO device
 */
void port_out(u16 port, u08 out) {
	__asm__ volatile ("outb %0, %1" : : "a" (out), "d" (port));
}
/**
 * Reads a byte from IO device
 */
u08 port_in (u16 port)
{
    u08 in;
    __asm__ volatile("inb %1, %0" : "=a" (in) : "d" (port));
    return in;
}
/**
 * Outputs a double word (4 bytes) to IO device
 */
void port_out_long(u16 port, u32 out) {
	__asm__ volatile ("outl %0, %1" : : "a" (out), "d" (port));
}
/**
 * Reads a double word from IO device
 */
u32 port_in_long (u16 port)
{
    u32 in;
    __asm__ volatile("inl %1, %0" : "=a" (in) : "d" (port));
    return in;
}

