#include<stdio.h>
#include<stdlib.h>

void test()
{
	int a = 10;//自动分配，自动回收 ，栈的运行与更新非常快

	printf("%p", &a);

	printf("\n");

}


void main()
{

	test();

	printf("\n\n");

	test();

	printf("\n\n");




	//auto int a = 10;自动变量



	getchar();

}
