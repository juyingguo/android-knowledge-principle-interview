#include <stdio.h>

extern void swi_handler(void);
/*�жϴ����ӳ���*/
void do_swi(int num)
{
	/*
	switch (num)
	{
		case 0x1: ...
		case 0x2: ...
	}
	*/
	printf("%d   helloworld\n", num);
}
//swi_handler
void install_swi_handler(void (*fun)(void))
{
	unsigned int cmd;
	//1.����һ����תָ��
	*((unsigned int *)0x38) = (unsigned int)fun;
	cmd = 0xe59ff028;
	//2.�Ѵ�ָ�������ŵ�0x8��ַ
	
	*((unsigned int *)0x8) = cmd;
}
int main(void)
{
	int i = 0;
	
	install_swi_handler(swi_handler);
	
	for (i = 0; i < 10; i++) {
		if (i == 3) {
			__asm
			{
				swi 0x123
			}
		}
		else
			printf("aa\n");
	}
	return 0;
}