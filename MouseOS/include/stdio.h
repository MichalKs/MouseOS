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
 * Basic functions
 */
#ifndef STDIO_H_
#define STDIO_H_

#include <types.h>
#define NULL (void *)0

void println(char* s);
void puts(char* s);
void putc (char c);
void putint (int i);
void puthex (u08 i);
char* itoa (int i);
char* itoa16 (int i);
int atoi(char *);
/**
 * integer to chars representing bits
 */
char* itoba(int i);
/**
 * Clear screen
 */
void cls();

void memset(char* address, int length, char value);
void hexdump(char* address, int length);


int isalpha (char c);
int isnum (char c);


#endif /* STDIO_H_ */
