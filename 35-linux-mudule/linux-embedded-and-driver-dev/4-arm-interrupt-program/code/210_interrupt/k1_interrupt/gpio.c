/* led1~led4 */
#define GPJ2CON	 *((volatile unsigned int *)0xe0200280)
#define GPJ2DAT  *((volatile unsigned int *)0xe0200284)
/* beep */
#define GPD0CON	 *((volatile unsigned int *)0xe02000a0)
#define GPD0DAT  *((volatile unsigned int *)0xe02000a4)
/* button */
#define GPH2CON	 *((volatile unsigned int *)0xe0200c40)
#define GPH2DAT  *((volatile unsigned int *)0xe0200c44)
//extern int c_entry(void);
void beep_init(void)
{
	GPD0CON = 0X1;
	GPD0DAT = 0;
}
void beep_on(void)
{
	GPD0DAT |= 0x1;
}
void beep_off(void)
{
	GPD0DAT &= ~0x1;
}


void led_init(void)
{
	GPJ2CON = 0x1111;
	GPJ2DAT = 0xF;
}

void led_on(int num)
{
	GPJ2DAT &= ~(1<<num);
}

void led_off(int num)
{
	GPJ2DAT |= (1<<num);
}
