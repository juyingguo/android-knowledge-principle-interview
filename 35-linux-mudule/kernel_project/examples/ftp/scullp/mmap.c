/*
 * mmap.c -- memory mapping for the scull-page char module
 *
 * Can't run with 1.2 or Sparc (unless you tweak it)
 * Tested with 2.0 on the x86
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

#include <linux/mm.h>     /* everything */
#include <linux/errno.h>  /* error codes */

#include <asm/pgtable.h>

#include "scullp.h"        /* local definitions */

/*
 * Don't try to compile mmap on the Sparc: symbols are not exported
 * Nor with old kernels, as the structures were different
 */
#if !defined(__sparc__) && (LINUX_VERSION_CODE >= VERSION_CODE(2,0,0))

/*
 * open and close: just keep track of how many times the device is
 * mapped, to avoid releasing it.
 */

void scullp_vma_open(struct vm_area_struct *vma)
{
    ScullP_Dev *dev = scullp_devices + MINOR(vma->vm_inode->i_rdev);

    dev->vmas++;
    MOD_INC_USE_COUNT;
}

void scullp_vma_release(struct vm_area_struct *vma)
{
    ScullP_Dev *dev = scullp_devices + MINOR(vma->vm_inode->i_rdev);

    dev->vmas--;
    MOD_DEC_USE_COUNT;
}

/*
 * The nopage method: the core of the file. It retrieves the
 * page required from the scullp device and returns it to the
 * user. The count for the page must be incremented, because
 * it is automatically decremented at page unmap.
 *
 * For this reason, "order" must be zero. Otherwise, only the first
 * page has its count incremented, and the allocating module must
 * release it as a whole block. Therefore, it isn't possible to map
 * pages from a multipage block: when they are unmapped, their count
 * is individually decreased, and would drop to 0.
 */

unsigned long scullp_vma_nopage(struct vm_area_struct *vma,
                                unsigned long address, int write)
{
    unsigned long offset = address - vma->vm_start + vma->vm_offset;
    ScullP_Dev *ptr, *dev = scullp_devices + MINOR(vma->vm_inode->i_rdev);
    void *pageptr = NULL; /* default to "missing" */

    if (offset >= dev->size) return 0; /* out of range: send SIGBUS */

    /*
     * Now retrieve the scullp device from the list,then the page.
     * Don't want to allocate: I'm too lazy. If the device has holes,
     * the process receives a SIGBUS when accessing the hole.
     */
    offset >>= PAGE_SHIFT; /* offset is a number of pages */
    for (ptr = dev; ptr && offset >= dev->qset;) {
        ptr = ptr->next;
        offset -= dev->qset;
    }
    if (ptr && ptr->data) pageptr = ptr->data[offset];
    if (!pageptr) return 0; /* hole or end-of-file: SIGBUS */

    /* got it, now increment the count */
    atomic_inc(&mem_map[MAP_NR(pageptr)].count);
    return (unsigned long)pageptr;
}

struct vm_operations_struct scullp_vm_ops = {
    scullp_vma_open,
    scullp_vma_release,
    NULL,            /* unmap */
    NULL,            /* protect */
    NULL,            /* sync */
    NULL,            /* advise */
    scullp_vma_nopage,
};


int scullp_mmap(struct inode *inode, struct file *filp,
                struct vm_area_struct *vma)
{
    /* refuse to map if order is not 0 */
    if (scullp_devices[MINOR(inode->i_rdev)].order)
        return -ENODEV;
    if (vma->vm_offset & (PAGE_SIZE-1))
        return -ENXIO; /* need aligned offsets */

    /* don't do anything here: "nopage" will fill the holes */
    vma->vm_ops = &scullp_vm_ops;
    vma->vm_inode = inode;
    inode->i_count++;
    scullp_vma_open(vma);
    return 0;
}

#else /* old or __sparc__ */

int scullp_mmap(struct inode *inode, struct file *filp,
                struct vm_area_struct *vma)
{
    return -ENODEV; /* like the kernel proper */
}

#endif /* old or __sparc__ */
