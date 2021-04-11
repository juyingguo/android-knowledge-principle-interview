#include<stdio.h>
#include<stdlib.h>
#include<iostream>


//默认参数必须放在右边
//默认参数中间不允许出现不默认的

void print(int c,int a = 1, int d=2, int b = 3)
{
	std::cout << a<<b<<c << std::endl;

}

void print(double c)
{

}



void main()
{
	//print(1,2,3);
	//函数指针没有默认参数，必须全部输入数据
	//函数重载与函数默认参数冲突,需要你输入的参数类型不一个，个数不一样，顺序不一样不会出现问题，否则一定报错
	void(*pt1)(int c, int a , int d , int b ) = print;
	pt1(100,1,2,3);//函数指针调用，没有用默认的

	print(100);


	system("pause");
}