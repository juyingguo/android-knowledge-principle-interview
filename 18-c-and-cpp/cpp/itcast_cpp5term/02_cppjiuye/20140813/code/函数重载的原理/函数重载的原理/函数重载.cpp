#include<iostream>
#include<stdio.h>
//�����ĸ��������������Ͳ�ͬ��˳��ͬ,����ֵ�޹�
void go(int a)
{

	std::cout << a;

}
void go(double a)
{
	std::cout << a;

}
void go(double a,int b )
{
	std::cout << a << b;

}

void go(int  a, double b)
{
	std::cout << a << b;


}

//int go(double a)
//{
//
//
//}



//void go(int a,int b)
//{
//
//}


void main1()
{
	void(*pgo1)(int a)=go;
	void(*pgo2)(double a)=go;
	void(*pgo3)(double a, int b)=go;
	void(*pgo4)(int  a, double b)=go;
	printf("%p\n",pgo1);
	printf("%p\n", pgo2);
	printf("%p\n", pgo3);
	printf("%p\n", pgo4);





	getchar();

}