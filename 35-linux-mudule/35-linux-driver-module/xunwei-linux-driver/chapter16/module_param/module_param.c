#include <linux/init.h>
/*������ʼ���궨���ͷ�ļ�,�����е�module_init��module_exit�ڴ��ļ���*/
#include <linux/module.h>
/*������ʼ������ģ���ͷ�ļ�,�����е�MODULE_LICENSE�ڴ�ͷ�ļ���*/

/*����module_param module_param_array��ͷ�ļ�*/
#include <linux/moduleparam.h>
/*����module_param module_param_array��perm��ͷ�ļ�*/
#include <linux/stat.h>


MODULE_LICENSE("Dual BSD/GPL");
/*�����ǿ�Դ�ģ�û���ں˰汾����*/
MODULE_AUTHOR("iTOPEET_dz");
/*��������*/

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
	/*��ӡ��Ϣ��KERN_EMERG��ʾ������Ϣ*/
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_EMERG "[%s,%s] %s,%s Hello world exit!\n",__DATE__,__TIME__,__FILE__,__func__);
}


module_init(hello_init);
/*��ʼ������*/
module_exit(hello_exit);
/*ж�غ���*/