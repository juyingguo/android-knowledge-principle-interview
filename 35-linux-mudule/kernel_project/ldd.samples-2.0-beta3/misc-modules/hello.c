/*                                                     
 *                                                     
 * Tested with 2.0, 2.2, 2.4 on x86      -             
 * Tested with 2.0           on SPARC                  
 * Tested with 2.0           on Alpha                  
 * Tested with      2.2      on ARM                    
 * Tested with      2.2      on PowerPC                
 * Tested with      2.2      on SPARC64                
 */                                                    
#define MODULE
#include <linux/module.h>

/*                                                        
 * These lines, although not shown in the book,           
 * are needed to make hello.c run properly even when      
 * your kernel has version support enabled                
 */                                                       
#include <linux/config.h>                                 
#ifdef CONFIG_MODVERSIONS                                 
#  define MODVERSIONS                                     
#  include <linux/modversions.h>                          
#endif                                                    
                                                          
int init_module(void)      { printk("<1>Hello, world\n"); return 0; }
void cleanup_module(void)  { printk("<1>Goodbye cruel world\n"); }
