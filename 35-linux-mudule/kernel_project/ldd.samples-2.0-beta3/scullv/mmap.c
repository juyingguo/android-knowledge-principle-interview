/*  -*- C -*-
 * mmap.c -- memory mapping for the scullv char module
 *
 * $Id: _mmap.c.in,v 1.9 2000/10/22 16:06:12 rubini Exp $
 */

#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

#include <linux/config.h>
#define __NO_VERSION__
#include <linux/module.h>
#include <linux/mm.h>     /* everything */
#include <linux/errno.h>  /* error codes */
#include <asm/pgtable.h>

#include "scullv.h"        /* local definitions */

#ifdef LINUX_20
static struct mm_struct *init_mm_ptr;

static void retrieve_init_mm_ptr(void)
{
    struct task_struct *p;

    for (p = current ; (p = p->next_task) != current ; )
        if (p->pid == 0)
            break;

    init_mm_ptr = p->mm;
}
#endif



/*
 * Given a VMA, get our device pointer from it.
 */
static inline ScullV_Dev *scullv_vma_to_dev (struct vm_area_struct *vma)
{
#if defined(LINUX_24)
    return (ScullV_Dev *) vma->vm_private_data;
#elif defined(LINUX_22)
    struct inode *inode = INODE_FROM_F(vma->vm_file); 
    return scullv_devices + MINOR(inode->i_rdev);
#else /* LINUX_20 */
    return scullv_devices + MINOR(vma->vm_inode->i_rdev);
#endif
}

/*
 * open and close: just keep track of how many times the device is
 * mapped, to avoid releasing it.
 */

void scullv_vma_open(struct vm_area_struct *vma)
{
    ScullV_Dev *dev = scullv_vma_to_dev(vma);

    dev->vmas++;
    MOD_INC_USE_COUNT;
}

void scullv_vma_close(struct vm_area_struct *vma)
{
    ScullV_Dev *dev = scullv_vma_to_dev(vma);

    dev->vmas--;
    MOD_DEC_USE_COUNT;
}

/*
 * The nopage method: the core of the file. It retrieves the
 * page required from the scullv device and returns it to the
 * user. The count for the page must be incremented, because
 * it is automatically decremented at page unmap.
 *
 * For this reason, "order" must be zero. Otherwise, only the first
 * page has its count incremented, and the allocating module must
 * release it as a whole block. Therefore, it isn't possible to map
 * pages from a multipage block: when they are unmapped, their count
 * is individually decreased, and would drop to 0.
 */

struct page *scullv_vma_nopage(struct vm_area_struct *vma,
                                unsigned long address, int write)
{
    unsigned long offset;
    ScullV_Dev *ptr, *dev = scullv_vma_to_dev(vma);
    struct page *page = NOPAGE_SIGBUS;
    void *pageptr = NULL; /* default to "missing" */
    pgd_t *pgd; pmd_t *pmd; pte_t *pte;
    unsigned long lpage;

    down(&dev->sem);
    offset = (address - vma->vm_start) + (vma->vm_pgoff << PAGE_SHIFT);
    if (offset >= dev->size) goto out; /* out of range */

    /*
     * Now retrieve the scullv device from the list,then the page.
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
    lpage = VMALLOC_VMADDR(pageptr);
    pgd = pgd_offset(&init_mm, lpage);
    pmd = pmd_offset(pgd, lpage);
    pte = pte_offset(pmd, lpage);
    page = pte_page(*pte);
    
    /* got it, now increment the count */
    get_page(page);
out:
    up(&dev->sem);
    return page;
}


#ifndef LINUX_24
unsigned long scullv_vma_nopage_old(struct vm_area_struct *vma,
                unsigned long address, int write)
{
    struct page *page = scullv_vma_nopage(vma, address, write);
    if (page)
#ifdef LINUX_20
        return (page->map_nr << PAGE_SHIFT);
#else  /* 2.2 */
        return (unsigned long) __va ((page - mem_map) << PAGE_SHIFT);
#endif
    return 0;
}
#endif


struct vm_operations_struct scullv_vm_ops = {
    open:     scullv_vma_open,
    close:  scullv_vma_close,
#ifdef LINUX_24
    nopage:   scullv_vma_nopage,
#else
    nopage:   scullv_vma_nopage_old,
#endif
};


#ifndef LINUX_20
int scullv_mmap(struct file *filp, struct vm_area_struct *vma)
{
    struct inode *inode = INODE_FROM_F(filp);


#ifdef LINUX_22					
    if (vma->vm_offset & (PAGE_SIZE-1))		
        return -ENXIO; /* need aligned offsets */	
#endif						

    /* don't do anything here: "nopage" will fill the holes */
    vma->vm_ops = &scullv_vm_ops;
#ifdef LINUX_24					
    vma->vm_private_data = scullv_devices + MINOR(inode->i_rdev);
#endif						
    vma->vm_file = filp;
    scullv_vma_open(vma);
    return 0;
}

#else /* LINUX_20 */
int scullv_mmap(struct inode *inode, struct file *filp,
                struct vm_area_struct *vma)
{

    if (vma->vm_offset & (PAGE_SIZE-1))
        return -ENXIO; /* need aligned offsets */

    /*
     * A pointer to init_mm is needed to access page tables
     */
    if (!init_mm_ptr)
        retrieve_init_mm_ptr();

    /* don't do anything here: "nopage" will fill the holes */
    vma->vm_ops = &scullv_vm_ops;
    vma->vm_inode = inode;
    inode->i_count++;
    scullv_vma_open(vma);
    return 0;
}

#endif /* LINUX_20 */
