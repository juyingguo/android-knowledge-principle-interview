#include<stdio.h>
#include<stdlib.h>

#define N  50
struct mystack
{
	int top;//栈顶
	int data[N];//存放数据
};
struct mystack  selfstack = { -1, {0} };//栈的初始化

int is_empty();//1 为空 0 非空
void setempty();//栈设置为空
int  push(int num);//压入数据 ，成功1，失败返回0
int pop();//弹出数据

int is_empty()
{
	if (selfstack.top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

void  setempty()
{
	selfstack.top = -1;//设置栈为空
}

int  push(int num)
{
	if (selfstack.top == N - 1)//栈溢出
	{
		return 0;//失败
	}
	else
	{
		selfstack.top += 1;//下标移动一个
		selfstack.data[selfstack.top] = num;//压入数据
		return 1;
	}
}

int pop()
{
	if (selfstack.top == -1)
	{
		return -1;//栈为空
	}
	else
	{
		selfstack.top -= 1;
		return selfstack.data[selfstack.top + 1];//返回弹出的数据
	}




}

void  main22()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 10; i++)
	{
		push(a[i]);//填充数据
	}
	while (!is_empty())
	{
		printf("%d\n", pop());//输出数据
	}




	system("pause");
}

void main()
{
	int num = 10;

	while (num)
	{
		push(num % 2);//压入数据
		num /= 2;//循环

	}
	while (!is_empty())
	{
		printf("%d", pop());//输出数据
	}


	system("pause");


}
