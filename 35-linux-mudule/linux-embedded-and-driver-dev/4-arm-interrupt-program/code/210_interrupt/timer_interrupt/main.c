#include "gpio.h"

// Timer
#define TCFG0		(*(volatile unsigned int *)0xE2500000)
#define TCFG1		(*(volatile unsigned int *)0xE2500004)
#define TCON		(*(volatile unsigned int *)0xE2500008)
#define TCNTB0		(*(volatile unsigned int *)0xE250000C)
#define TCMPB0		(*(volatile unsigned int *)0xE2500010)
#define TCNTO0		(*(volatile unsigned int *)0xE2500014)
#define TINT_CSTAT	(*(volatile unsigned int *)0xE2500044)
 
// VIC
#define VIC0RAWINTR             (*(volatile unsigned int *)0xF2000008)
#define VIC0IRQSTATUS           (*(volatile unsigned int *)0xF2000000)
#define VIC0FIQSTATUS           (*(volatile unsigned int *)0xF2000004)
#define VIC0INTENABLE           (*(volatile unsigned int *)0xF2000010)
#define VIC0INTSELECT           (*(volatile unsigned int *)0xF200000C)
#define VIC0VECTADDR21          (*(volatile unsigned int *)0xF2000154)

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
	// clear pending bit    
        TINT_CSTAT |= 1<<5;

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
	 VIC0VECTADDR21 = (unsigned int)fun;
}
void interrupt_init(void)
{
	/* 1.中断源使能 */
	// PCLK / (65+1) = 1M
	TCFG0 = 65;
	// 1M/16 = 62500hz
	TCFG1 = 0x4;
	// 1s = 62500hz
	TCNTB0 = 62500;
	// Set the manual update bit 
	TCON |= 1<<1;
	// and clear only manual update bit 
	TCON &= ~(1<<1);
	// step 3: Set the start bit 
	TCON |= 1<<0;
	// set auto-reload bit
	TCON |= 1<<3;		
	// step 4: Enable interrupt TINT_CSTAT bit[0] 
	TINT_CSTAT |= 1<<0;
	
	/* 2.中断控制器使能 */
	// VIC0INTSELECT  0xF200_000C R/W 	0:IRQ	1:FIQ
	//*(int *)0xF200000C |= (1<<21);		// enable FIQ
	VIC0INTSELECT &= ~(1<<21);		// enable IRQ

	// (VICINTENABLE, R/W, Address=0xF200_0010,
	VIC0INTENABLE |= (1<<21);		// enable EINT[21]
	
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
