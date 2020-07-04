/*
 * Simple - REALLY simple memory mapping demonstration.
 * $Id: simple.c,v 1.1 2001/01/26 20:25:15 corbet Exp $
 */

#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

#include <linux/config.h>
#include <linux/module.h>

#include <linux/kernel.h>   /* printk() */
#include <linux/malloc.h>   /* kmalloc() */
#include <linux/fs.h>       /* everything... */
#include <linux/errno.h>    /* error codes */
#include <linux/types.h>    /* size_t */
#include <linux/init.h>     /* module_init */
#include <asm/page.h>

#include "sysdep.h"

static int simple_major = 0;
MODULE_PARM(simple_major, "i");
MODULE_AUTHOR("Jonathan Corbet");

/*
 * Forwards for our methods.
 */
int simple_open (struct inode *inode, struct file *filp);
int simple_release(struct inode *inode, struct file *filp);
int simple_remap_mmap(struct file *filp, struct vm_area_struct *vma);
int simple_nopage_mmap(struct file *filp, struct vm_area_struct *vma);


/*
 * Our various sub-devices.
 */
/* Device 0 uses remap_page_range */
struct file_operations simple_remap_ops = {
    open:    simple_open,
    release: simple_release,
    mmap:    simple_remap_mmap,
};

/* Device 1 uses nopage */
struct file_operations simple_nopage_ops = {
    open:    simple_open,
    release: simple_release,
    mmap:    simple_nopage_mmap,
};

#define MAX_SIMPLE_DEV 2

struct file_operations *simple_fops[MAX_SIMPLE_DEV] = {
    &simple_remap_ops,
    &simple_nopage_ops,
};

/*
 * Open the device; all we have to do here is to up the usage count and
 * set the right fops.
 */
int simple_open (struct inode *inode, struct file *filp)
{
    unsigned int dev = MINOR(inode->i_rdev);

    if (dev >= MAX_SIMPLE_DEV) 
        return -ENODEV;
    filp->f_op = simple_fops[dev];
    MOD_INC_USE_COUNT;
    return 0;
}


/*
 * Closing is even simpler.
 */
int simple_release(struct inode *inode, struct file *filp)
{
    MOD_DEC_USE_COUNT;
    return 0;
}



/*
 * Common VMA ops.
 */

void simple_vma_open(struct vm_area_struct *vma)
{ MOD_INC_USE_COUNT; }

void simple_vma_close(struct vm_area_struct *vma)
{ MOD_DEC_USE_COUNT; }


/*
 * The remap_page_range version of mmap.
 */

static struct vm_operations_struct simple_remap_vm_ops = {
    open:  simple_vma_open,
    close: simple_vma_close,
};

int simple_remap_mmap(struct file *filp, struct vm_area_struct *vma)
{
    unsigned long offset = vma->vm_pgoff << PAGE_SHIFT;

    if (offset >= __pa(high_memory) || (filp->f_flags & O_SYNC))
        vma->vm_flags |= VM_IO;
    vma->vm_flags |= VM_RESERVED;

    if (remap_page_range(vma->vm_start, offset, vma->vm_end-vma->vm_start,
                vma->vm_page_prot))
        return -EAGAIN;

    vma->vm_ops = &simple_remap_vm_ops;
    simple_vma_open(vma);
    return 0;
}



/*
 * The nopage version.
 */
struct page *simple_vma_nopage(struct vm_area_struct *vma,
                unsigned long address, int write_access)
{
    struct page *pageptr;
    unsigned long physaddr = address - vma->vm_start +
            (vma->vm_pgoff << PAGE_SHIFT);
    pageptr = virt_to_page(__va(physaddr));
    get_page(pageptr);
    return pageptr;
}
        
static struct vm_operations_struct simple_nopage_vm_ops = {
    open:    simple_vma_open,
    close:   simple_vma_close,
    nopage:  simple_vma_nopage,
};


int simple_nopage_mmap(struct file *filp, struct vm_area_struct *vma)
{
    unsigned long offset = vma->vm_pgoff << PAGE_SHIFT;

    if (offset >= __pa(high_memory) || (filp->f_flags & O_SYNC))
        vma->vm_flags |= VM_IO;
    vma->vm_flags |= VM_RESERVED;

    vma->vm_ops = &simple_nopage_vm_ops;
    simple_vma_open(vma);
    return 0;
}



/*
 * Module housekeeping.
 */
static int simple_init(void)
{
    int result;

    result = register_chrdev(simple_major, "simple", &simple_remap_ops);
    if (result < 0)
    {
        printk(KERN_WARNING "simple: unable to get major %d\n", simple_major);
        return result;
    }
    if (simple_major == 0)
        simple_major = result;
    return 0;
}


static void simple_cleanup(void)
{
    unregister_chrdev(simple_major, "simple");
}


module_init(simple_init);
module_exit(simple_cleanup);
