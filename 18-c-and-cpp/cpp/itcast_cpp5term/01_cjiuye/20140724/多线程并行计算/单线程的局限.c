#include <stdio.h>
#include<Windows.h>
#include<process.h>//进程
#include<stdlib.h>

struct MyStruct
{
	int num;
	double data;
};


void  run(void *p)
{
	int *px = (int *)p;//指针转换
	//printf("线程%d启动", *px);
	char str[100] = {0};//字符数组
	sprintf(str, "线程%d启动", *px);

	MessageBoxA(0,str, "多线程", 0);
}


void main()
{

	for (int i = 0; i < 5; i++)
	{
		//run(NULL);
		_beginthread(run, 0, &i);

		Sleep(10);
	}



	system("pause");

}
