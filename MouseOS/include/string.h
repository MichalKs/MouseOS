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
 * Managing strings
 */
#ifndef STRING_H_
#define STRING_H_



int strlen(char* s);
char* strrev(char* s);
void strcpy (char* dst, const char* src, int max_lenght);
char* strcat (char* dst, const char* src);
int strcmp(const char *s1, const char*s2);
char* strstr(char* s, char* s1);
char *strtok(char *s1, const char *s2);



#endif /* STRING_H_ */
