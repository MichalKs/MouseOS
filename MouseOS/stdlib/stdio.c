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

#include <display.h>
#include <stdio.h>
#include <string.h>

static char zero_string[2]="0";
static char zero_string_hex[3]="00";

void memset(char* address, int length, char value) {
	while (length--) {
		*address++=value;
	}
}

void puts(char* s) {
	display_string(s);
}

void putc(char c) {
	display_char(c);
}

void putint(int i) {
	puts(itoa(i));
}
void puthex(u08 i) {
	puts(itoa16(i));
}

void println(char* s) {
	display_string(s);
	display_string("\n");
}

void cls() {
	clear_screen();
}
void hexdump(char* address, int length) {
	int count=0;
	while (length--) {
		puthex(*address++);
		putc(' ');
		if(count++==15) {
			count=0;
			putc('\n');
		}
	}
}

char* itoa(int val) {

	char string[32];

	int i=0;
	int digit;
	if (val==0) {
		return zero_string;
	}
	while (val>0 && i<32) {
		digit=val%10;
		val=val/10;
		string[i]='0'+digit;
		i++;
	}
	string[i]='\0';
	char* ret=strrev(string);
	return ret;
}

char* itoa16(int val) {

	char string[32];

	int i=0;
	int digit;
	if (val==0) {
		return zero_string_hex;
	}
	while (val>0 && i<32) {
		digit=val%16;
		val=val/16;
		if (digit<10) {
			string[i]='0'+digit;
		}
		else {
			// '7'+10='A'
			string[i]='7'+digit;
		}

		i++;
	}
	if (i%2!=0) {
		string[i++]='0';
	}
	string[i]='\0';
	char* ret=strrev(string);
	return ret;
}

int atoi (char* c) {

	int i=strlen(c);
	int result=0;
	int position=1;
	while (i>0) {
		result+= ( c[i-1]-'0' ) *position;
		position*=10;
		i--;
	}
	return result;
}

char* itoba(int i) {
	char bits[32];

	int j,mod;
	j=mod=0;
	if (i==0) {
		return zero_string;
	}
	while (i>0) {
		mod=i%2;
		i=i/2;
		if (mod==0)
			bits[j]='0';
		else
			bits[j]='1';
		j++;
	}
	bits[j]='\0';
	char* ret=strrev(bits);

	return ret;
}

int isalpha (char c) {

	if ((c>'0' && c<'9') || (c>'A' && c<'Z') || (c>'a' && c<'z'))
		return 1;
	else
		return 0;
}
int isnum (char c) {
	if (c>'0' && c<'9')
		return 1;
	else
		return 0;
}



