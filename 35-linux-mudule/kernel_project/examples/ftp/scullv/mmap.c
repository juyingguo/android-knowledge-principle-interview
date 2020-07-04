/*
 * mmap.c -- memory mapping for the scull-virtual char module
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

#include "scullv.h"        /* local definitions */

/*
 * Don't try to compile mmap on the Sparc: symbols are not exported
 * Nor with old kernels, as the structures were different
 */
#if !defined(__sparc__) && (LINUX_VERSION_CODE >= VERSION_CODE(2,0,0))

/*
 * retrieve a pointer to init_mm, which is not exported
 */

static struct mm_struct *init_mm_ptr;

static void retrieve_init_mm_ptr(void)
{
    struct task_struct *p;

    for (p = current ; (p = p->next_task) != current ; )
        if (p->pid == 0)
            break;

    init_mm_ptr = p->mm;
}

/*
 * open and close: just keep track of how many times the device is
 * mapped, to avoid releasing it.
 */

void scullv_vma_open(struct vm_area_struct *vma)
{
    ScullV_Dev *dev = scullv_devices + MINOR(vma->vm_inode->i_rdev);

    dev->vmas++;
    MOD_INC_USE_COUNT;
}

void scullv_vma_release(struct vm_area_struct *vma)
{
    ScullV_Dev *dev = scullv_devices + MINOR(vma->vm_inode->i_rdev);

    dev->vmas--;
    MOD_DEC_USE_COUNT;
}

/*
 * The nopage method: the core of the file. It retrieves the
 * page required from the scullv device and returns it to the
 * user. The count for the page must be incremented, because
 * it is automatically decremented at page unmap.
 *
 * There's no limit to order (unlike scullp) becase
 * vmalloc() builds regions from singe pages
 */

unsigned long scullv_vma_nopage(struct vm_area_struct *vma,
                                unsigned long address, int write)
{
    unsigned long offset = address - vma->vm_start + vma->vm_offset;
    ScullV_Dev *ptr, *dev = scullv_devices + MINOR(vma->vm_inode->i_rdev);
    unsigned long allocsize;
    void *pageptr = NULL;
    unsigned long page;
    pgd_t *pgd; pmd_t *pmd; pte_t *pte;

    if (offset >= dev->size) return 0; /* out of range: send SIGBUS */

    /*
     * Retrieve the scullv device from the list, then the page.
     * Don't allocate: if the page is missing return 0
     */
    offset >>= PAGE_SHIFT; /* offset is a number of pages */
    allocsize = 1 << dev->order;
    for (ptr = dev; ptr && offset >= dev->qset * allocsize;) {
        ptr = ptr->next;
        offset -= dev->qset * allocsize;
    }
    if (ptr && ptr->data)
        pageptr = ptr->data[offset/allocsize];
    if (!pageptr) return 0; /* hole or end-of-file: SIGBUS */
    pageptr += (offset % allocsize) << PAGE_SHIFT;


    /*
     * After scullv lookup, "page" is now the address of the page
     * needed by the current process. Since it's a vmalloc address,
     * first retrieve the unsigned long value to be looked up
     * in page tables.
     */
    page = VMALLOC_VMADDR(pageptr);

    pgd = pgd_offset(init_mm_ptr, page);
    pmd = pmd_offset(pgd, page);
    pte = pte_offset(pmd, page);
    page = pte_page(*pte);        /* this is the physical address */

    /* now increment the count and return */
    atomic_inc(&mem_map[MAP_NR(page)].count);
    return page;
}

#if 0
    if (pte_page(*pte)) /* already mapped? shouldn't happen, but... */
        return pte_page(*pte);
#endif


struct vm_operations_struct scullv_vm_ops = {
    scullv_vma_open,
    scullv_vma_release,
    NULL,            /* unmap */
    NULL,            /* protect */
    NULL,            /* sync */
    NULL,            /* advise */
    scullv_vma_nopage,
};


int scullv_mmap(struct inode *inode, struct file *filp,
                struct vm_area_struct *vma)
{
    /* refuse to map if order is not 0 */
    if (vma->vm_offset & (PAGE_SIZE-1))
        return -ENXIO; /* need aligned offsets */

    /* don't do anything here: "nopage" will fill the holes */
    vma->vm_ops = &scullv_vm_ops;
    vma->vm_inode = inode;
    inode->i_count++;
    scullv_vma_open(vma);
    /*
     * A pointer to init_mm is needed to access page tables
     */
    if (!init_mm_ptr)
        retrieve_init_mm_ptr();
    return 0;
}

#else /* old or __sparc__ */

int scullv_mmap(struct inode *inode, struct file *filp,
                struct vm_area_struct *vma)
{
    return -ENODEV; /* like the kernel proper */
}

#endif /* old or __sparc__ */
