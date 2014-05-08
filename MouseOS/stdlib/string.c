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

#include <string.h>

int strlen(char* s) {
	int i=0;
	while (*s++) {
		i++;
	}
	return i;
}

char* strrev(char* s) {

	static char string[100];

	int imax=strlen(s);
	if (imax>100) {
		imax=100;
	}
	int i,j=0;
	for (i=imax-1;i>=0;i--) {
		string[j]=s[i];
		j++;
	}
	string[imax]=0;

	return string;
}
