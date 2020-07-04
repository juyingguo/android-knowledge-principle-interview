/*
 * pcidata.c --  a module that dumps the cfg registers through /proc
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

/*
 * This simple module offers in a /proc file the binary
 * configuration data of available PCI devices.
 * Each device has 256 bytes of cfg data: 16 devices
 * can fit in a page (32 on the alpha).
 */

int pcimod_read_proc(char *buf, char **start, off_t offset,
                   int len, int unused)
{
    int i, pos=0;
    int bus, fun;
    unsigned char headertype=0;
    unsigned int id;

    if (!pcibios_present())
        return sprintf(buf,"No PCI bios present\n");

    /*
     * This code is derived from "drivers/pci/pci.c". This means that
     * the GPL applies to this source file and credit is due to the
     * original authors (Drew Eckhardt, Frederic Potter, David
     * Mosberger-Tang)
     */
    for (bus=0; !bus; bus++) { /* only bus 0 :-) */
        for (fun=0; fun < 0x100 && pos < PAGE_SIZE; fun++) {
            if (!PCI_FUNC(fun)) /* first function */
                pcibios_read_config_byte(bus,fun,PCI_HEADER_TYPE,&headertype);
            else if (!(headertype&0x80))
                continue;
            pcibios_read_config_dword(bus,fun,PCI_VENDOR_ID, &id);
            if (!id || id==~0) {
                headertype=0; continue;
            }

            /* Ok, we've found a device, copy its cfg space to the buffer*/
            for (i=0; i<256; i+=4, pos+=4)
                pcibios_read_config_dword(bus,fun,i,(u32 *)(buf+pos));
        }
    }
    return pos;
}

struct proc_dir_entry pcimod_proc_entry = {
        0,                 /* low_ino: the inode -- dynamic */
        7, "pcidata",      /* len of name and name */
        S_IFREG | S_IRUGO, /* mode */
        1, 0, 0,           /* nlinks, owner, group */
        0, NULL,           /* size - unused; operations -- use default */
        &pcimod_read_proc,   /* function used to read data */
        /* nothing more */
    };


int init_module(void)
{
    proc_register_dynamic(&proc_root, &pcimod_proc_entry);
    return 0;
}

void cleanup_module(void)
{
    proc_unregister(&proc_root, pcimod_proc_entry.low_ino);
    return;
}

#endif /* version 1.99.4 or newer */
