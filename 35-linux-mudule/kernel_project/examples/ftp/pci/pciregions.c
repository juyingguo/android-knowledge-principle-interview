/*
 * pciregions.c --  a module that prints address regions of PCI boards
 *
 * Tested with 1.2 on the x86
 * Tested with 2.0 on the x86
 *
 * Copyright (C) 1997   rubini@linux.it (Alessandro Rubini)
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

#define __NO_VERSION__ /* don't define kernel_verion in module.h */
#include <linux/module.h>
#include <linux/version.h>

char kernel_version [] = UTS_RELEASE;

#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/proc_fs.h>
#include <linux/bios32.h> /* pcibios_* */
#include <linux/pci.h>

/*
 * Refuse to compile under versions older than 1.99.4
 */

#define VERSION_CODE(vers,rel,seq) ( ((vers)<<16) | ((rel)<<8) | (seq) )

#if LINUX_VERSION_CODE < VERSION_CODE(1,99,4)
#  error "This module needs Linux 1.99.4 or newer"
#else

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
                   int len, int unused)
{
    int i, pos=0;
    int bus, fun;
    unsigned char headertype=0;
    u32 id32;
    u16 vendorid, deviceid;
    #define PRINTF(fmt, args...) sprintf(buf+len, fmt, ## args)
    len=0;

    /* Loop through the devices (code not printed in the book) */

    if (!pcibios_present())
        return sprintf(buf,"No PCI bios present\n");

    /*
     * This code is derived from "drivers/pci/pci.c". This means that
     * the GPL applies to this source file and credit is due to the
     * original authors (Drew Eckhardt, Frederic Potter, David
     * Mosberger-Tang)
     */
    bus=0; /* only bus 0 :-) */
    for (fun=0; fun < 0x100 && pos < PAGE_SIZE; fun++) {
        if (!PCI_FUNC(fun)) /* first function */
            pcibios_read_config_byte(bus,fun,PCI_HEADER_TYPE,&headertype);
            else if (!(headertype&0x80))
                continue;
        pcibios_read_config_dword(bus,fun,PCI_VENDOR_ID, &id32);
        if (!id32 || id32==~0) {
            headertype=0; continue;
        }
        
        if (len > PAGE_SIZE - 1024) /* a big margin, just to be sure */
            return len;
        pcibios_read_config_word(bus,fun,PCI_VENDOR_ID,&vendorid);
        pcibios_read_config_word(bus,fun,PCI_DEVICE_ID,&deviceid);

        /* A device was found: print its regions */
        len += PRINTF("Bus %i, device %2i, fun %2i (id %04x-%04x)\n",
                       bus, fun>>3, fun & 7, vendorid, deviceid);
        for (i=0; addresses[i]; i++) {
            u32 curr, mask;
            char *type;

            pcibios_read_config_dword(bus,fun,addresses[i],&curr);
            cli();
            pcibios_write_config_dword(bus,fun,addresses[i],~0);
            pcibios_read_config_dword(bus,fun,addresses[i],&mask);
            pcibios_write_config_dword(bus,fun,addresses[i],curr);
            sti();
            
            len += PRINTF("\tregion %i: mask 0x%08lx, now at 0x%08lx\n", i,
                           (unsigned long)mask,
                           (unsigned long)curr);
            if (!mask) {
                len += PRINTF("\tregion %i not existent\n", i);
                break;
            }
            /* extract the type, and the programmable bits */
            if (mask & PCI_BASE_ADDRESS_SPACE) {
                type = "I/O"; mask &= PCI_BASE_ADDRESS_IO_MASK;
            } else {
                type = "mem"; mask &= PCI_BASE_ADDRESS_MEM_MASK;
            }
            len += PRINTF("\tregion %i: type %s, size %i\n", i,
                          type, ~mask+1);
        }
    } /* fun */
    return len;
}

struct proc_dir_entry pciregions_proc_entry = {
        0,                 /* low_ino: the inode -- dynamic */
       10, "pciregions",   /* len of name and name */
        S_IFREG | S_IRUGO, /* mode */
        1, 0, 0,           /* nlinks, owner, group */
        0, NULL,           /* size - unused; operations -- use default */
        &pciregions_read_proc,   /* function used to read data */
        /* nothing more */
    };


int init_module(void)
{
    proc_register_dynamic(&proc_root, &pciregions_proc_entry);
    return 0;
}

void cleanup_module(void)
{
    proc_unregister(&proc_root, pciregions_proc_entry.low_ino);
    return;
}

#endif /* version 1.99.4 or newer */
