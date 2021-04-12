#include<iostream>
#include<stdlib.h>
//自动变量，自动获取类型，输出，泛型
//自动变量，可以实现自动循环一维数组
//自动循环的时候，对应的必须是常量



void main1()
{
	auto num = 10.9;//自动变量，自动匹配类型
	auto numA = 10/3.0;
	std::cout << num <<"     " << numA << std::endl;
	system("pause");


}

void main()
{
	//int num[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	double num[2][5] = { 1.0, 2.0, 3.0, 4.5, 5, 6, 7, 8, 9, 10 };
	//num数组名是一个指针常量
	//auto 自动循环 begin  endl;，必须是一个数组的常量
	//
	for (auto data : num)//泛型C++语法,循环一维数组,常量
	{
		std::cout << data<<std::endl;
		
		for (int i = 0; i < 5; i++)
		{
			std::cout << *(data + i) << std::endl;
		}
	}
	system("pause");


}