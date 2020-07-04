/*
 * snull.c --  the Simple Network Utility
 *
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
#include <linux/kernel.h> /* printk() */
#include <linux/malloc.h> /* kmalloc() */
#include <linux/errno.h>  /* error codes */
#include <linux/types.h>  /* size_t */
#include <linux/interrupt.h> /* mark_bh */

#include <linux/netdevice.h>   /* struct device, and other headers */
#include <linux/etherdevice.h> /* eth_type_trans */
#include <linux/ip.h>          /* struct iphdr */
#include <linux/tcp.h>         /* struct tcphdr */
#include <linux/skbuff.h>

#include "sysdep-2.1.h"

#if LINUX_VERSION_CODE > VERSION_CODE(2,1,7)
#  include <linux/in6.h>    /* needed by checksum.h */
#endif

#include <asm/checksum.h>

#include "snull.h"

/* This is a load-time options */
static int eth = 0; /* Call yourself "ethX". Default is "sn0"/"sn1" */

int snull_eth;


/*
 * This structure is private to each device. It is used to pass
 * packets in and out, so there is place for a packet
 */

struct snull_priv {
    struct enet_statistics stats;
    int packetlen;
    int status;
    u8 *packetdata;
};

extern struct device snull_devs[];
        
/*
 * Open and close
 */

int snull_open(struct device *dev)
{
    int i;

    /* request_region(), request_irq(), ....  (like fops->open) */

#if 0
    /*
     * We have no irq line, otherwise this assignment can be used to
     * grab a non-shared interrupt. To share interrupt lines use
     * the dev_id argument of request_irq. Seel snull_interrupt below.
     */
    irq2dev_map[dev->irq] = dev;
#endif

    /* 
     * Assign the hardware address of the board: use "\0SNULx", where
     * x is 0 or 1. The first byte is '\0': a safe choice with regard
     * to multicast
     */
    for (i=0; i < ETH_ALEN; i++)
        dev->dev_addr[i] = "\0SNUL0"[i];
    dev->dev_addr[ETH_ALEN-1] += (dev - snull_devs); /* the number */

    dev->start = 1;
    dev->tbusy = 0;
    MOD_INC_USE_COUNT;
    return 0;
}

int snull_release(struct device *dev)
{
    /* release ports, irq and such -- like fops->close */

    dev->start = 0;
    dev->tbusy = 1; /* can't transmit any more */
    MOD_DEC_USE_COUNT;
    /* if irq2dev_map was used, zero the entry here */
    return 0;
}

/*
 * Configuration changes (passed on by ifconfig)
 */
int snull_config(struct device *dev, struct ifmap *map)
{
    if (dev->flags & IFF_UP) /* can't act on a running interface */
        return -EBUSY;

    /* Don't allow changing the I/O address */
    if (map->base_addr != dev->base_addr) {
        printk(KERN_WARNING "snull: Can't change I/O address\n");
        return -EOPNOTSUPP;
    }

    /* Allow changing the IRQ */
    if (map->irq != dev->irq) {
        dev->irq = map->irq;
        /* request_irq() is delayed to open-time */
    }

    /* ignore other fields */
    return 0;
}

/*
 * Receive a packet: retrieve, encapsulate and pass over to upper levels
 */
void snull_rx(struct device *dev, int len, unsigned char *buf)
{
    struct sk_buff *skb;
    struct snull_priv *privp = (struct snull_priv *)dev->priv;
    /*
     * The packet has been retrieved from the transmission
     * medium. Build an skb around it, so upper layers can handle it
     */

    skb = dev_alloc_skb(len+2);
    if (!skb) {
        printk("snull rx: low on mem\n");
        return;
    }
    skb_reserve(skb, 2); /* align IP on 16B boundary */  
    memcpy(skb_put(skb, len), buf, len);

    /* Write metadata, and then pass to the receive level */
    skb->dev = dev;
    skb->protocol = eth_type_trans(skb, dev);
    skb->ip_summed = CHECKSUM_UNNECESSARY; /* don't check it */
    privp->stats.rx_packets++;
    netif_rx(skb);
    return;
}
    
        
/*
 * The typical interrupt entry point (1.3.70 and later)
 */
void snull_interrupt(int irq, void *dev_id, struct pt_regs *regs)
{
    int statusword;
    struct snull_priv *privptr;
    /*
     * As usual, check the "device" pointer for shared handlers.
     * Then assign "struct device *dev"
     */
#if 0
    /* This is the way to do things for non-shared handlers */
    struct device *dev = (struct device *)(irq2dev_map[irq]);
#else
    /* Otherwise use this SA_SHIRQ-safe approach */
    struct device *dev = (struct device *)dev_id;
    /* ... and check with hw if it's really ours */
#endif

    if (!dev /*paranoid*/ ) return;
    dev->interrupt = 1; /* lock */

    /* retrieve statusword: real netdevices use inb() or inw() */
    privptr = (struct snull_priv *)(dev->priv);
    statusword = privptr->status;
    if (statusword & SNULL_RX_INTR) {
        /* send it to snull_rx for handling */
        snull_rx(dev, privptr->packetlen, privptr->packetdata);
    }
    if (statusword & SNULL_TX_INTR) {
        /* a transmission is over: tell we are no more busy */
        privptr->stats.tx_packets++;
        dev->tbusy = 0;
        mark_bh(NET_BH);
    }
    dev->interrupt = 0; /* release lock */
    return;
}



/*
 * Transmit a packet (low level interface)
 */
void snull_hw_tx(char *buf, int len, struct device *dev)
{
    /*
     * This function deals with hw details. This interface loops
     * back the packet to the other snull interface (if any).
     * In other words, this function implements the snull behaviour,
     * while all other procedures are rather device-independent
     */
    struct iphdr *ih;
    struct device *dest;
    struct snull_priv *privp;
    u32 *saddr, *daddr;

    /* I am paranoid. Ain't I? */
    if (len < sizeof(struct ethhdr) + sizeof(struct iphdr)) {
        printk("snull: Hmm... packet too short (%i octets)\n",
               len);
        return;
    }

    if (0) { /* enable this conditional to look at all the data */
        int i;
        PDEBUG("snull: len is %i\n" KERN_DEBUG "data:",len);
        for (i=14 ; i<len; i++)
            printk(" %02x",buf[i]&0xff);
        printk("\n");
    }
    /*
     * Ethhdr is 14 bytes, but the kernel arranges for iphdr
     * to be aligned (i.e., ethhdr is unaligned)
     */
    ih = (struct iphdr *)(buf+sizeof(struct ethhdr));
    saddr = &ih->saddr;
    daddr = &ih->daddr;

    ((u8 *)saddr)[2] ^= 1; /* change the third octet (class C) */
    ((u8 *)daddr)[2] ^= 1;

    ih->check = 0;         /* and rebuild the checksum (ip needs it) */
    ih->check = ip_fast_csum((unsigned char *)ih,ih->ihl);

    if (dev == snull_devs)
        PDEBUGG("%08lx:%05i --> %08lx:%05i\n",
               ntohl(ih->saddr),ntohs(((struct tcphdr *)(ih+1))->source),
               ntohl(ih->daddr),ntohs(((struct tcphdr *)(ih+1))->dest));
    else
        PDEBUGG("%08lx:%05i <-- %08lx:%05i\n",
               ntohl(ih->daddr),ntohs(((struct tcphdr *)(ih+1))->dest),
               ntohl(ih->saddr),ntohs(((struct tcphdr *)(ih+1))->source));

    /*
     * Ok, now the packet is ready for transmission: first send a
     * receive interrupt on the twin device, then send a
     * transmission-done to the transmitting device
     */

    dest = snull_devs + (dev==snull_devs ? 1 : 0);
    privp = (struct snull_priv *)dest->priv;
    privp->status = SNULL_RX_INTR;
    privp->packetlen = len;
    privp->packetdata = buf;
    snull_interrupt(0, dest, NULL);

    privp = (struct snull_priv *)dev->priv;
    privp->status = SNULL_TX_INTR;
    snull_interrupt(0, dev, NULL);
}

/*
 * Transmit a packet (called by the kernel)
 */
int snull_tx(struct sk_buff *skb, struct device *dev)
{
    int len, retval=0;
    char *data;

    if (dev->tbusy) {/* shouldn't happen */
        retval = -EBUSY;
        goto tx_done;
    }
    if (skb == NULL) {
        PDEBUG("tint for %p\n",dev);
        dev_tint(dev); /* we are ready to transmit */
        return 0;
    }
    dev->tbusy = 1; /* transmission is busy */

    len = ETH_ZLEN < skb->len ? skb->len : ETH_ZLEN; /* minimum len */
    data = skb->data;
    dev->trans_start = jiffies; /* save the timestamp */

    /* actual deliver of data is device-specific, and not shown here */
    snull_hw_tx(data, len, dev);

  tx_done:
    dev_kfree_skb(skb, FREE_WRITE); /* release it */

    return retval; /* zero == done; nonzero == fail */
}

/*
 * Ioctl commands 
 */
int snull_ioctl(struct device *dev, struct ifreq *rq, int cmd)
{
 
    PDEBUG("ioctl\n");
    return 0;
}

/*
 * Return statistics to the caller
 */
struct enet_statistics *snull_stats(struct device *dev)
{
    struct snull_priv *priv = (struct snull_priv *)dev->priv;
    return &priv->stats;
}

/*
 * This function is called to fill up an eth header, since arp is not
 * available on the interface
 */
#ifdef __USE_OLD_REBUILD_HEADER__
int snull_rebuild_header(void *buff, struct device *dev, unsigned long dst,
		    struct sk_buff *skb)
{
    struct ethhdr *eth = (struct ethhdr *)buff;
#else
int snull_rebuild_header(struct sk_buff *skb)
{
    struct device *dev = skb->dev;
    struct ethhdr *eth = (struct ethhdr *)skb->data;
#endif

    memcpy(eth->h_source, dev->dev_addr, dev->addr_len);
    memcpy(eth->h_dest, dev->dev_addr, dev->addr_len);
    eth->h_dest[ETH_ALEN-1]   ^= 0x01;   /* dest is us xor 1 */
    return 0;
}


/*
 * The "change_mtu" method is usually not needed.
 * If you need it, it must be like this.
 */
int snull_change_mtu(struct device *dev, int new_mtu)
{
    /* chack ranges */
    if ((new_mtu < 68) || (new_mtu > 1500))
        return -EINVAL;
    /*
     * Do anything you need, and the accept the value
     */
    dev->mtu = new_mtu;
    return 0; /* success */
}

/*
 * The init function (sometimes called probe).
 * It is invoked by register_netdev()
 */
int snull_init(struct device *dev)
{
#if 0
    /*
     * Make the usual checks: check_region(), probe irq, ...  -ENODEV
     * should be returned if no device found.  No resource should be
     * grabbed: this is done on open(). 
     */
#endif

    /* 
     * Then, assign other fields in dev, using ether_setup() and some
     * hand assignments
     */
    ether_setup(dev); /* assign some of the fields */

    dev->open            = snull_open;
    dev->stop            = snull_release;
    dev->set_config      = snull_config;
    dev->hard_start_xmit = snull_tx;
    dev->do_ioctl        = snull_ioctl;
    dev->get_stats       = snull_stats;
    dev->change_mtu      = snull_change_mtu;  
    dev->rebuild_header = snull_rebuild_header;
    /* keep the default flags, just add NOARP */
    dev->flags           |= IFF_NOARP;

    /*
     * Then, allocate the priv field. This encloses the statistics
     * and a few private fields.
     */
    dev->priv = kmalloc(sizeof(struct snull_priv), GFP_KERNEL);
    if (dev->priv == NULL)
        return -ENOMEM;
    memset(dev->priv, 0, sizeof(struct snull_priv));
    return 0;
}

/*
 * The devices
 */

char snull_names[16]; /* two eight-byte buffers */
struct device snull_devs[2] = {
    {
        snull_names, /* name -- set at load time */
        0, 0, 0, 0,  /* shmem addresses */
        0x000,       /* ioport */
        0,           /* irq line */
        0, 0, 0,     /* various flags: init to 0 */
        NULL,        /* next ptr */
        snull_init,  /* init function, fill other fields with NULL's */
    },
    {
        snull_names+8,/* name -- set at load time */
        0, 0, 0, 0,  /* shmem addresses */
        0x000,       /* ioport */
        0,           /* irq line */
        0, 0, 0,     /* various flags: init to 0 */
        NULL,        /* next ptr */
        snull_init,  /* init function, fill other fields with NULL's */
    }
};

/*
 * Finally, the module stuff
 */

int init_module(void)
{

    int result, i, device_present = 0;

    snull_eth = eth; /* copy the cfg datum in the non-static place */

    if (!snull_eth) { /* call them "sn0" and "sn1" */
        memcpy(snull_devs[0].name, "sn0", 4);
        memcpy(snull_devs[1].name, "sn1", 4);
    } else { /* use automatic assignment */
        snull_devs[0].name[0] = snull_devs[1].name[0] = ' ';
    }

    for (i=0; i<2;  i++)
        if ( (result = register_netdev(snull_devs + i)) )
            printk("snull: error %i registering device \"%s\"\n",
                   result, snull_devs[i].name);
        else device_present++;
#ifndef SNULL_DEBUG
    REGISTER_SYMTAB(NULL); /* hide symbols */
#endif

    return device_present ? 0 : -ENODEV;
}

void cleanup_module(void)
{
    int i;
   
    for (i=0; i<2;  i++) {
        kfree(snull_devs[i].priv);
        unregister_netdev(snull_devs + i);
    }
    return;
}






