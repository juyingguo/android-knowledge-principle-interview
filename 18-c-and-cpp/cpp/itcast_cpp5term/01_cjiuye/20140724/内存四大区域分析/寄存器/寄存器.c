#include<stdio.h>
#include<stdlib.h>

void main1()
{
	int  a = 1;

	int b = a + 1;
	//a + 1 = 2;


	b = a + 2;

	b = a + 3;


	getchar();
}


void main()
{
    /*
	//register  int a = 3;
	//&a;//地址是内存的地址，CPU没有地址;寄存器在内存里面没有实体，就无法保存里面的内容。

	int a = 10;
	int b;//b=a+5;
	_asm{
		mov eax, a

		add eax, 5

	    mov  b,eax

	}
	printf("%d", b);

	getchar();
	*/

    int a=10,b;
    asm("movl %1, %%eax;
         movl %%eax, %0;"
        :"=r"(b)          /*输出部*/
        :"r"(a)           /*输入部*/
        :"%eax"           /*修正部*/
       );





}
