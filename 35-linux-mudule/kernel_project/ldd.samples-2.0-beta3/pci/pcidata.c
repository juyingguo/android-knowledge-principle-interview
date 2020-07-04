/*
 * pcidata.c --  a module that dumps the cfg registers through /proc
 *
 * $Id: pcidata.c,v 1.3 2000/06/14 07:55:50 rubini Exp $
 * Tested with 2.0 on the x86
 * Tested with 2.2 on the x86
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
#include <linux/proc_fs.h>
#include <linux/pci.h>

#include "sysdep.h"

#ifdef LINUX_24
#  warning "This module has only been compiled and tested with kernels 2.0/2.2"
#endif

/*
 * This simple module offers in a /proc file the binary
 * configuration data of available PCI devices.
 * Each device has 256 bytes of cfg data: 16 devices
 * can fit in a page (32 on the alpha).
 * FIXME: page size is no longer an issue with 2.2/2.4
 */

int pcidata_read_proc(char *buf, char **start, off_t offset,
                   int len, int *eof, void *data)
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
    *eof=1;
    return pos;
}

#ifdef USE_PROC_REGISTER

static int pcidata_old_read_proc(char *buf, char **start, off_t offset,
				 int len, int unused)
{
    int eof;
    return pcidata_read_proc(buf, start, offset, len, &eof, NULL);
}


struct proc_dir_entry pcimod_proc_entry = {
        0,                 /* low_ino: the inode -- dynamic */
        7, "pcidata",      /* len of name and name */
        S_IFREG | S_IRUGO, /* mode */
        1, 0, 0,           /* nlinks, owner, group */
        0, NULL,           /* size - unused; operations -- use default */
        &pcidata_old_read_proc,   /* function used to read data */
        /* nothing more */
    };

#endif /* USE_PROC_REGISTER */

int init_module(void)
{
#ifdef USE_PROC_REGISTER
    proc_register_dynamic(&proc_root, &pcimod_proc_entry);
#else
    create_proc_read_entry("pcidata", 0, NULL, pcidata_read_proc, NULL);
#endif
    return 0;
}

void cleanup_module(void)
{
#ifdef USE_PROC_REGISTER
    proc_unregister(&proc_root, pcimod_proc_entry.low_ino);
#else
    remove_proc_entry("pcidata", 0);
#endif
    return;
}

