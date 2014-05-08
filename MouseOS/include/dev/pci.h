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

#ifndef PCI_H_
#define PCI_H_

/**
 * IO ports for PCI configuration
 */
#define PCI_CONFIG_ADDRESS 	0xcf8
#define PCI_CONFIG_DATA 	0xcfc

/**
 * Config address fields description
 */

#define PCI_CONFIG_ENABLE 	31 // enable bit
// bits 24-30 are reserved
#define PCI_CONFIG_BUS		16 	// 8 bit bus number
#define PCI_CONFIG_DEVICE	11 	// 5 bit device number on bus
#define PCI_CONFIG_FUNCTION	8	// 3 bit function number of the device
#define PCI_CONFIG_REGISTER	2	// 6 bit register number in device's configuration space
// bits 0 and 1 are always 0

/**
 * Maximum values from the above fields
 */
#define PCI_MAX_BUS 		256
#define PCI_MAX_DEVICE		32
#define PCI_MAX_FUNCTION	8
#define PCI_MAX_REGISTER	64

/**
 * Configuration registers (their addresses and fields - indented) present in all header types.
 */
#define PCI_DEVICE_VENDOR 	0x00
	#define PCI_DEVICE_ID	16
	#define PCI_VENDOR_ID	0
#define PCI_STATUS_COMMAND	0x04
	#define PCI_STATUS		16
	#define PCI_COMMAND		0
#define PCI_CLASS_SUBCLASS	0x08
	#define PCI_CLASS		24
	#define PCI_SUBCLASS	16
	#define PCI_PROG_IF		8
	#define PCI_REVISION	0
#define PCI_BIST_HEADER		0x0c
	#define PCI_BIST		24
	#define PCI_HEADER_TYPE	16
	#define PCI_LATENCY		8
	#define PCI_CACHE_SIZE	0
#define PCI_BAR0			0x10
#define PCI_BAR1			0x14
#define PCI_BAR2			0x18
#define PCI_BAR3			0x1c
#define PCI_BAR4			0x20
#define PCI_BAR5			0x24
/**
 * Configuration registers (their addresses and fields - indented) present in header 0x00 types
 * - general device.
 */
#define PCI_CARDBUS_CIS_PTR	0x28
#define PCI_SUBSYSTEM		0x2c
	#define PCI_SUBSYSTEM_ID		0x16
	#define PCI_SUBSYSTEM_VENDOR	0
#define PCI_EXPANSION_ROM_BASE		0x30
#define PCI_CAPABILITIES_PTR		0x34
#define PCI_RESERVED				0x38
#define PCI_INTERRUPTS				0x3c
	#define PCI_MAX_LATENCY	24
	#define PCI_MIN_GRANT	16
	#define PCI_INTERRUPT_PIN	8
	#define PCI_INTERRUPT_LINE	0


void pci_discover();



#endif /* PCI_H_ */
