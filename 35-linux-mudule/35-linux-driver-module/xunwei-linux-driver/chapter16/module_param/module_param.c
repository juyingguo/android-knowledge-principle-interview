#include <linux/init.h>
/*包含初始化宏定义的头文件,代码中的module_init和module_exit在此文件中*/
#include <linux/module.h>
/*包含初始化加载模块的头文件,代码中的MODULE_LICENSE在此头文件中*/

/*定义module_param module_param_array的头文件*/
#include <linux/moduleparam.h>
/*定义module_param module_param_array中perm的头文件*/
#include <linux/stat.h>


MODULE_LICENSE("Dual BSD/GPL");
/*声明是开源的，没有内核版本限制*/
MODULE_AUTHOR("iTOPEET_dz");
/*声明作者*/

static int module_arg1,module_arg2;
static int int_array[50];
static int int_num;

module_param(module_arg1,int,S_IRUSR);

module_param(module_arg2,int,S_IRUSR);

module_param_array(int_array,int,&int_num,S_IRUSR);


static int hello_init(void)
{
	int i;
	
	printk(KERN_EMERG "[%s,%s] %s,%s module_arg1 is %d!\n",__DATE__,__TIME__,__FILE__,__func__,module_arg1);
	printk(KERN_EMERG "[%s,%s] %s,%s module_arg2 is %d!\n",__DATE__,__TIME__,__FILE__,__func__,module_arg2);
	
	for(i=0;i<int_num;i++){
		printk(KERN_EMERG "[%s,%s] %s,%s int_array[%d] is %d!\n",__DATE__, __TIME__,__FILE__,__func__,i,int_array[i]);
	}
		
	printk(KERN_EMERG "[%s,%s] %s,%s Hello World enter!\n",__DATE__,__TIME__,__FILE__,__func__);
	/*打印信息，KERN_EMERG表示紧急信息*/
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_EMERG "[%s,%s] %s,%s Hello world exit!\n",__DATE__,__TIME__,__FILE__,__func__);
}


module_init(hello_init);
/*初始化函数*/
module_exit(hello_exit);
/*卸载函数*/