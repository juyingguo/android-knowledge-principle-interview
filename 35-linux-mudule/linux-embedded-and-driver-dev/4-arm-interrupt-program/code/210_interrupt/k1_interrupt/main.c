#include "gpio.h"

// GPIO
#define GPH2CON         	(*(volatile unsigned int *)0xE0200C40)
#define GPH2DAT         	(*(volatile unsigned int *)0xE0200C44)
#define EXT_INT_2_PEND          (*(volatile unsigned int *)0xE0200F48)
#define EXT_INT_2_CON           (*(volatile unsigned int *)0xE0200E08)
#define EXT_INT_2_MASK          (*(volatile unsigned int *)0xE0200F08)

// VIC
#define VIC0RAWINTR             (*(volatile unsigned int *)0xF2000008)
#define VIC0IRQSTATUS           (*(volatile unsigned int *)0xF2000000)
#define VIC0FIQSTATUS           (*(volatile unsigned int *)0xF2000004)
#define VIC0INTENABLE           (*(volatile unsigned int *)0xF2000010)
#define VIC0INTSELECT           (*(volatile unsigned int *)0xF200000C)
#define VIC0VECTADDR16          (*(volatile unsigned int *)0xF2000140)

#define VIC0ADDRESS             (*(volatile unsigned int *)0xF2000F00)


extern void irq_handler(void);
extern void cpsr_I_clear(void);

void delay(int sec)
{
	int i, j;
	for (i = 0; i < sec; i++)
		for (j = 0; j < 0x40000; j++)
			;
}
void do_irq(void)
{
	/* 清除PENDING 寄存器相关位 */ 
	/* 如果PENDING 寄存器不清零，执行中断完成后，会继续触发中断 */
	/* 下面的写法比较粗暴，会将所有的PENDING位都清零，真实处理中，只需要对应清零PENDING位 */
	EXT_INT_2_PEND = EXT_INT_2_PEND;

	beep_on();
	delay(1);
	beep_off();

	VIC0ADDRESS = 0;
}
void irq_handler_install(void (*fun)(void))
{
	/*异常向量表入口地址0x18*/
	//0xD0037418 ---> 0x38
	//*((unsigned int *)0xD0037418) = (unsigned int)fun;
	VIC0VECTADDR16 = (unsigned int)fun;
}
void interrupt_init(void)
{
	/* 1.中断源使能 */
	GPH2CON = 0xF;	
	EXT_INT_2_CON = 0x2;	
	EXT_INT_2_MASK &= ~(1<<0);
	EXT_INT_2_PEND = EXT_INT_2_PEND;
	/* 2.中断控制器使能 */
	VIC0INTENABLE |= 1<<16;
	VIC0INTSELECT &= ~(1<<16);
	/* 3.中断核心层使能 */
	cpsr_I_clear();
}
int c_entry(void)
{
	int i = 0;
	led_init();
	beep_init();
	/*安装中断处理函数*/
	irq_handler_install(irq_handler);
	/*打通中断三层模型*/
	interrupt_init();

	while(1) {
		led_on(i%4);
		delay(1);
		led_off(i%4);
		delay(1);
		i++;
	}
	return 0;
}
