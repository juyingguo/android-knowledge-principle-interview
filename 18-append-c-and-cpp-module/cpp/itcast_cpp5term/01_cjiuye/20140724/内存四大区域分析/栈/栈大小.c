#include<stdio.h>
#include<stdlib.h>


void main2x ()
{
	int a[1024*300];//1M=1024*1024  栈的大小编译器决定
	//无法使用较大内存，
	//用完了就立刻回收

	getchar();

}


void main()
{
	while (1)
	{
		//注入进程，卡死CPU，卡死内存
		double   db[1024 * 200];
		void  *p = malloc(1024 * 1024);
	}
	



}

