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


#include <dev/pci.h>
#include <stdio.h>
#include <ports.h>
#include <types.h>

static void pci_discover_device(u32 bus,u32 device);
static inline u32 pci_get_register(u32 bus,u32 device,u32 function, u32 reg);

void pci_discover() {

	u08 bus;
	u08 device;

	for (bus=0; bus<1;bus++) {
		for (device=0; device<PCI_MAX_DEVICE;device++) {
			pci_discover_device(bus,device);
		}
	}
}

static void pci_discover_device(u32 bus,u32 device) {
	u08 function=0;
	u32 reg=pci_get_register(bus,device,function,PCI_DEVICE_VENDOR);
	u16 vendor_id=reg>>PCI_VENDOR_ID;
	u16 device_id=reg>>PCI_DEVICE_ID;

	if (vendor_id==0xffff)
		return;
	reg=pci_get_register(bus,device,function,PCI_CLASS_SUBCLASS);
	puts("Device found. Vendor id: ");
	puts(itoa16(vendor_id));
	puts(". Device id: ");
	println(itoa16(device_id));
	println(itoa16(reg));
	puts("Class: ");
	puts(itoa16( (u08) (reg>>PCI_CLASS) ));
	puts(". Subclass: ");
	println(itoa16( (u08) (reg>>PCI_SUBCLASS) ));

}

static inline u32 pci_get_register(u32 bus,u32 device,u32 function,u32 reg) {
	port_out_long(PCI_CONFIG_ADDRESS,(1<<PCI_CONFIG_ENABLE)|
			(bus<<PCI_CONFIG_BUS)|(device<<PCI_CONFIG_DEVICE)|
			(function<<PCI_CONFIG_FUNCTION)|(reg<<PCI_CONFIG_REGISTER) );
	return port_in_long(PCI_CONFIG_DATA);

}

