/*
 * pciregions.c --  a module that prints address regions of PCI devices
 *
 * $Id: pciregions.c,v 1.2 2000/06/12 16:02:32 rubini Exp $
 * Tested with 2.0.36 on the x86
 * Tested with 2.2.16 on the x86
 * Tested with 2.2.13 on the Netwinder
 *
 * Copyright (C) 1997,2000   rubini@linux.it (Alessandro Rubini)
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

#include <linux/module.h>

#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/proc_fs.h>
#include <linux/pci.h>

#include "sysdep.h"

#ifdef LINUX_24
#  warning "This module has only been compiled and tested with kernels 2.0/2.2"
#endif

#ifndef PCI_HEADER_TYPE_NORMAL /* These definitions are missing from 2.0 */
#  define PCI_HEADER_TYPE_NORMAL 0
#  define PCI_HEADER_TYPE_BRIDGE 1
#  define   PCI_PRIMARY_BUS         0x18    /* Primary bus number */
#  define   PCI_SECONDARY_BUS       0x19    /* Secondary bus number */
#  define   PCI_SUBORDINATE_BUS     0x1a    /* Highest bus behind the bridge */
#  define PCI_HEADER_TYPE_CARDBUS 2
#  define   PCI_CB_PRIMARY_BUS      0x18    /* PCI bus number */
#  define   PCI_CB_CARD_BUS         0x19    /* CardBus bus number */
#  define   PCI_CB_SUBORDINATE_BUS  0x1a    /* Subordinate bus number */
#endif

static u32 addresses[] = {
    PCI_BASE_ADDRESS_0,
    PCI_BASE_ADDRESS_1,
    PCI_BASE_ADDRESS_2,
    PCI_BASE_ADDRESS_3,
    PCI_BASE_ADDRESS_4,
    PCI_BASE_ADDRESS_5,
    0
};

int pciregions_read_proc(char *buf, char **start, off_t offset,
                   int len, int *eof, void *data)
{
    int i, pos=0;
    int bus, fun, is_multi = 0;
    unsigned char headertype, pribus, secbus;
    u32 longword;
    u16 vendorid, deviceid;

    /* to print information about several buses, keep an array of them */
    #define MAXNBUS 8
    int buses[MAXNBUS] = {0,};
    int lastbus = 0; /* only one bus, by default, bus 0 */
    int busindex = 0;

    #define PRINTF(fmt, args...) sprintf(buf+len, fmt, ## args)
    len=0;

    /* Loop through the devices (code not printed in the book) */

    if (!pcibios_present())
        return sprintf(buf, "No PCI bios present\n");

    bus = buses[busindex]; /* first bus (bus 0) */
    for (fun=0; pos < PAGE_SIZE; fun++) {

	/*
	 * A clean implementation
	 * would have a separate function to dump a single bus, but i
	 * preferred to keep it in one function to include part of it
	 * in the book (the printed code is automagically extracted from
	 * this file).
	 *
	 * Instead, I use a dirty trick to fold two loops in one.
	 */
	if (fun > 0xff) { /* end of this bus */
	    if (busindex == lastbus) break; 
	    /* loop over to the next bus */
	    bus = buses[++busindex];
	    fun = 0;
	}

	/*
	 * This code is derived from "drivers/pci/pci.c". This means that
	 * the GPL applies to this source file and credit is due to the
	 * original authors (Drew Eckhardt, Frederic Potter, David
	 * Mosberger-Tang)
	 */

        if (PCI_FUNC(fun) && !is_multi) /* not multi-function */
	    continue;
	
	pcibios_read_config_byte(bus, fun, PCI_HEADER_TYPE, &headertype);
        if (!PCI_FUNC(fun)) /* first function */
	    is_multi = headertype & 0x80;
	headertype &= 0x7f; /* mask multi-function bit */

        pcibios_read_config_dword(bus,fun,PCI_VENDOR_ID, &longword);
        if (longword == 0xffffffff || longword == 0x00000000) {
            is_multi = 0; continue;
        }
        
	/* FIXME: should get rid of the PAGE_SIZE limit */
        if (len > PAGE_SIZE - 160) { /* a big margin, just to be sure */
	    *eof = 1; return len;
	}
        pcibios_read_config_word(bus,fun,PCI_VENDOR_ID,&vendorid);
        pcibios_read_config_word(bus,fun,PCI_DEVICE_ID,&deviceid);

        len += PRINTF("Bus %i, device %2i, fun %2i (id %04x-%04x,"
		      " headertype 0x%02x)\n",
		      bus, fun>>3, fun & 7,
		      vendorid, deviceid, headertype);
	if (headertype == PCI_HEADER_TYPE_BRIDGE) {
	    /* This is a bridge, print what it does */
	    pcibios_read_config_byte(bus,fun,PCI_PRIMARY_BUS,&pribus);
	    pcibios_read_config_byte(bus,fun,PCI_SECONDARY_BUS,&secbus);
	    len += PRINTF("\tbridge connecting PCI bus %i to PCI bus %i\n",
			  secbus, pribus);
	    /* remember about this bus, to dump it later */
	    if (lastbus <= MAXNBUS-1) {
		lastbus++;
		buses[lastbus] = secbus;
		len += PRINTF("\t(bus %i is dumped below)\n", secbus);
	    } else {
		len += PRINTF("\t(bus %i won't be dumped)\n", secbus);
	    }
	    continue;
	} else if (headertype == PCI_HEADER_TYPE_CARDBUS) {
	    /* This is a CardBus bridge, print what it does */
	    pcibios_read_config_byte(bus,fun,PCI_CB_PRIMARY_BUS,&pribus);
	    pcibios_read_config_byte(bus,fun,PCI_CB_CARD_BUS,&secbus);
	    len += PRINTF("\tbridge connecting CardBus %i to PCI bus %i\n",
			  secbus, pribus);
	    continue;
	} else if (headertype != PCI_HEADER_TYPE_NORMAL) {
	    len += PRINTF("\tunknown header type, skipping\n");
	    continue;
	}
		
        /* Print the address regions of this device */
        for (i=0; addresses[i]; i++) {
            u32 curr, mask;
            char *type;

            pcibios_read_config_dword(bus,fun,addresses[i],&curr);
            cli();
            pcibios_write_config_dword(bus,fun,addresses[i],~0);
            pcibios_read_config_dword(bus,fun,addresses[i],&mask);
            pcibios_write_config_dword(bus,fun,addresses[i],curr);
            sti();

            if (!mask)
		continue; /* there may be other regions */

	    /* apply the I/O or memory mask to current position */
	    /* FIXME: handle 64-bit regiorns */
	    if (curr & PCI_BASE_ADDRESS_SPACE_IO)
		curr &= PCI_BASE_ADDRESS_IO_MASK;
	    else
		curr &= PCI_BASE_ADDRESS_MEM_MASK;
		
            len += PRINTF("\tregion %i: mask 0x%08lx, now at 0x%08lx\n", i,
                           (unsigned long)mask,
                           (unsigned long)curr);
            /* extract the type, and the programmable bits */
            if (mask & PCI_BASE_ADDRESS_SPACE_IO) {
                type = "I/O"; mask &= PCI_BASE_ADDRESS_IO_MASK;
            } else {
                type = "mem"; mask &= PCI_BASE_ADDRESS_MEM_MASK;
            }
            len += PRINTF("\tregion %i: type %s, size %i\n", i,
                          type, ~mask+1);
	    if (len > PAGE_SIZE - 160) {
		*eof = 1; return len;
	    }
        }
    } /* fun */
    *eof = 1;
    return len;
}

#ifdef USE_PROC_REGISTER

static int pciregions_old_read_proc(char *buf, char **start, off_t offset,
				 int len, int unused)
{
    int eof;
    return pciregions_read_proc(buf, start, offset, len, &eof, NULL);
}


struct proc_dir_entry pciregions_proc_entry = {
        0,                 /* low_ino: the inode -- dynamic */
       10, "pciregions",   /* len of name and name */
        S_IFREG | S_IRUGO, /* mode */
        1, 0, 0,           /* nlinks, owner, group */
        0, NULL,           /* size - unused; operations -- use default */
        &pciregions_old_read_proc,   /* function used to read data */
        /* nothing more */
    };

#endif /* USE_PROC_REGISTER */


int init_module(void)
{
#ifdef USE_PROC_REGISTER
    proc_register_dynamic(&proc_root, &pciregions_proc_entry);
#else
    create_proc_read_entry("pciregions", 0, NULL, pciregions_read_proc, NULL);
#endif
    return 0;
}

void cleanup_module(void)
{
#ifdef USE_PROC_REGISTER
    proc_unregister(&proc_root, pciregions_proc_entry.low_ino);
#else
    remove_proc_entry("pciregions", 0);
#endif
}

