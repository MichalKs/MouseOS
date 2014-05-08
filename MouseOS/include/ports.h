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
 * Accessing I/O ports.
 */
#ifndef PORTS_H_
#define PORTS_H_

#include <types.h>

void port_out (u16 port, u08 out);
u08 port_in (u16 port);
void port_out_long(u16 port, u32 out);
u32 port_in_long (u16 port);


#endif /* PORTS_H_ */
