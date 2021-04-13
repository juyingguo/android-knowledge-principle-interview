#include <stdio.h>
#include<iostream>//加以区分C++的头文件，还是C语言的头文件
#include<stdlib.h>
//using namespace std;




void main1()
{
	//C++注重类型，强类型，严格检查类型
	int *p1=NULL;
	double *p2=NULL;
	//p1 = p2; C语言类型检查不明确


}


void  main2()
{
	//int  a = 5;
	//int a(5);
	//double a(3.5);
	//char *str = "1234";
	//char *str("china");
	wchar_t *str(L"china");
	//cout << str;
	//wcout << str;宽字符，汉字，棒子文
	system("pause");


}

void main()
{
	//输出符 <<
	//std 命名空间
	//::域控制符
	std::cout << "hello world";
}