
#include<iostream>//C++没有.h加以区分C/C++
//C/C++头文件  有没有命名空间
#include<stdlib.h>
//int a = 1;
extern  int a;//C++要求严格
void main()
{
	int a = 3;
	std::cout << ::a;

	system("pause");
}