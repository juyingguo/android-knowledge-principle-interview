#include<stdio.h>

int  a = 1;//C 出现重名无法引用全局变量
void main()
{
	printf("%d\n", a);
	int a = 3;
	printf("%d\n",a);


	getchar();
}