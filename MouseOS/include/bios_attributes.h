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


#ifndef BIOS_ATTRIBUTES_H_
#define BIOS_ATTRIBUTES_H_

/**
 * Colors used by VGA controller in attribute bytes.
 */

//  					Hex 	 	Color
#define BLACK 			0x00 // 	Black
#define BLUE 			0x01 //	 	Blue
#define GREEN 			0x02 //	 	Green
#define CYAN			0x03 //	 	Cyan
#define REF 			0x04 //	 	Red
#define MAGENTA 		0x05 // 	Magenta
#define BROWN			0x06 //	 	Brown
#define LIGHT_GRAY		0x07 //	 	Light Gray
#define DARK_GRAY		0x08 //	 	Dark Gray
#define LIGHT_BLUE		0x09 //	 	Light Blue
#define LIGHT_GREEN 	0x0A //	 	Light Green
#define LIGHT_CYAN		0x0B //	 	Light Cyan
#define LIGHT_RED		0x0C //	 	Light Red
#define LIGHT_MAGENTA	0x0D //	 	Light Magenta
#define YELLOW			0x0E //	 	Yellow
#define WHITE			0x0F //	 	White

/**
 * @todo insert BIOS data area structure
 */

struct _bios_data_area {
	u08 bios;
}__attribute__((packed));



#endif /* BIOS_ATTRIBUTES_H_ */
