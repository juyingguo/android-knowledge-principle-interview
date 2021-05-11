#ifndef __GPIO_H
#define __GPIO_H
void beep_init(void);
void beep_on(void);
void beep_off(void);
void led_init(void);
void led_on(int num);
void led_off(int num);
#endif
