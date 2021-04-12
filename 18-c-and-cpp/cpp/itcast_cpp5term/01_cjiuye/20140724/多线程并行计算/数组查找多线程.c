#define  _CRT_SECURE_NO_WARNINGS//关闭安全检查
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>


void gogogo(void *p)
{
	int *px = (int*)p;//指针转换


	//return ; //线程执行完成以后返回
	int i = 0;
	while (1)
	{
		if (i > 5)
		{
			printf("%d   %d\n", i,*px);
			_endthread();//结束线程
		}
		Sleep(1000);
		i++;

	}

}

void  time(void *p)
{
	int i = 0;
	while (1)
	{

		char str[100] = { 0 };
		sprintf(str, "title 当前时间第%d秒", i);
		system(str);
		i++;
		Sleep(1000);
	}
}


void main()
{
	//time(NULL);
	_beginthread(time, 0, NULL);

	for (int i = 0; i < 5; i++)
	{
		//gogogo(NULL);
		HANDLE  hd = _beginthread(gogogo, 0, &i);//hd是编号
		WaitForSingleObject(hd, INFINITE);//等待,阻塞模式  ，没有wait并行模式
		Sleep(1000);
	}

	getchar();




}
