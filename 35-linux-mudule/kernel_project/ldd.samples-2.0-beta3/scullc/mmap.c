/*
 * mmap.c -- memory mapping for the scullc char module
 */

#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

#include <linux/config.h>
#include <linux/module.h>
#include <linux/version.h>

#include <linux/mm.h>     /* everything */
#include <linux/errno.h>  /* error codes */

#include <asm/pgtable.h>

#include "scullc.h"        /* local definitions */

/*
 * Don't try to compile mmap on the Sparc: symbols are not exported (FIXME:?)
 * Nor with old kernels, as the structures were different
 */
#ifndef __sparc__

/*
 * open and close: just keep track of how many times the device is
 * mapped, to avoid releasing it.
 */

void scullc_vma_open(struct vm_area_struct *vma)
{
    struct inode *inode = INODE_FROM_F(vma->vm_file);
    ScullC_Dev *dev = scullc_devices + MINOR(inode->i_rdev);

    dev->vmas++;
    MOD_INC_USE_COUNT;
}

void scullc_vma_close(struct vm_area_struct *vma)
{
    struct inode *inode = INODE_FROM_F(vma->vm_file);
    ScullC_Dev *dev = scullc_devices + MINOR(inode->i_rdev);

    dev->vmas--;
    MOD_DEC_USE_COUNT;
}

/*
 * The nopage method: the core of the file. It retrieves the
 * page required from the scullc device and returns it to the
 * user. The count for the page must be incremented, because
 * it is automatically decremented at page unmap.
 *
 * For this reason, "order" must be zero. Otherwise, only the first
 * page has its count incremented, and the allocating module must
 * release it as a whole block. Therefore, it isn't possible to map
 * pages from a multipage block: when they are unmapped, their count
 * is individually decreased, and would drop to 0.
 */

struct page *scullc_vma_nopage(struct vm_area_struct *vma,
                                unsigned long address, int write)
{
    unsigned long offset;
    struct inode *inode = INODE_FROM_F(vma->vm_file);
    ScullC_Dev *ptr, *dev = scullc_devices + MINOR(inode->i_rdev);
    struct page *page = NOPAGE_SIGBUS;
    void *pageptr = NULL; /* default to "missing" */

    while (down_interruptible(&dev->sem))
        ;  /* Can't return ERESTARTSYS here */
    offset = (address - vma->vm_start) + (vma->vm_pgoff << PAGE_SHIFT);
    if (offset >= dev->size) goto out; /* out of range */

    /*
     * Now retrieve the scullc device from the list,then the page.
     * If the device has holes, the process receives a SIGBUS when
     * accessing the hole.
     */
    offset >>= PAGE_SHIFT; /* offset is a number of pages */
    for (ptr = dev; ptr && offset >= dev->qset;) {
        ptr = ptr->next;
        offset -= dev->qset;
    }
    if (ptr && ptr->data) pageptr = ptr->data[offset];
    if (!pageptr) goto out; /* hole or end-of-file */
    page = virt_to_page(pageptr);
    
    /* got it, now increment the count */
    atomic_inc(&page->count);
out:
    up(&dev->sem);
    return page;
}


#ifdef LINUX_20_VERSION
unsigned long scullc_vma_nopage(struct vm_area_struct *vma,
                                unsigned long address, int write)
{
    unsigned long offset = address - vma->vm_start + vma->vm_offset;
    ScullC_Dev *ptr, *dev = scullc_devices + MINOR(vma->vm_inode->i_rdev);
    void *pageptr = NULL; /* default to "missing" */

    if (offset >= dev->size) return 0; /* out of range: send SIGBUS */

    /*
     * Now retrieve the scullc device from the list,then the page.
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
#endif


struct vm_operations_struct scullc_vm_ops = {
    open:     scullc_vma_open,
    close:  scullc_vma_close,
    nopage:   scullc_vma_nopage,
};


int scullc_mmap(struct file *filp, struct vm_area_struct *vma)
{
    struct inode *inode = INODE_FROM_F(filp);

    /* refuse to map if order is not 0 */
    if (scullc_devices[MINOR(inode->i_rdev)].order)
        return -ENODEV;
#ifdef oldstuff
    if (vma->vm_offset & (PAGE_SIZE-1))
        return -ENXIO; /* need aligned offsets */
#endif

    /* don't do anything here: "nopage" will fill the holes */
    vma->vm_ops = &scullc_vm_ops;
    /* vma->vm_inode = inode; */
    /* inode->i_count++; */
    scullc_vma_open(vma);
    return 0;
}

#else /* old or __sparc__ */

int scullc_mmap(struct file *filp, struct vm_area_struct *vma)
{
    return -ENODEV; /* like the kernel proper */
}

#endif /* old or __sparc__ */
