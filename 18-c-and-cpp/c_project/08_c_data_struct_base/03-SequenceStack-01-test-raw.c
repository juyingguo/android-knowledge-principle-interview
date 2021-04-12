/*
1.顺序栈，使用数组静态分配内存.
2.栈顶位置初始化值为-1.
*/
#include<stdio.h>
#include<stdbool.h>					//bool（布尔类型的头文件）
//#include<string.h>
#define maxsize 20				//定义数组大小为20

typedef int elementype;		//int类型别名

typedef struct node{
	elementype data[maxsize];			//数据域
	elementype top;						//栈顶指针
}myStack;

void visit(elementype c)			//访问栈中的元素
{
	printf("%d ", c);
}

bool initstack(myStack *s)			//初始化栈
{
	//这里没有给data申请空间建应该是因为数组的大小已经定义完成
	s -> top = -1;//栈顶位置初始化值为-1
	return true;
}

bool stackempty(myStack s)			//判断栈是否为空
{
	if(s.top == -1)
		return true;
	else
		return false;
}

bool ClearStack(myStack *s) 		//将栈清空
{
        s -> top = -1;
        return true;
}

elementype length(myStack s)		//计算栈中元素的个数
{
	return s.top + 1;
}

bool getTop(myStack s, elementype *e)	//获得栈顶元素
{
	if(s.top == -1)
		return false;
	else
		*e = s.data[s.top];
	return true;
}

bool push(myStack *s, elementype e)			//元素e入栈
{
	if(s -> top == maxsize - 1)
		return false;
	else
	{
		s -> top++;				//栈顶指针加一
		s -> data[s -> top] = e;		//新插入的元素进栈
		return true;
	 }
}

void traverse(myStack s)		//遍历栈中元素并进行打印
{
	int i = 0;
	while(i <= s.top)
		visit(s.data[i++]);
	printf("\n");
}

bool pop(myStack *s, elementype *e)		//栈顶元素出栈
{
	if(s -> top == -1)
		return false;
	else
	{
		*e = s -> data[s -> top];
		s -> top--;			//栈顶指针减一
		return true;
	}
}

int main()
{
	myStack s;
	int j, e;
	if(initstack(&s) == 1)
	{
		for(j = 1;j <= 10;j++)
			push(&s, j);
	}
	puts("进栈之后的元素依次为： ");
	traverse(s);

	pop(&s, &e);
	printf("弹出的栈顶元素为 %d \n", e);
	printf("弹出栈顶元素之后的栈是否为空(1:空 0:否)%d\n", stackempty(s));
    getTop(s, &e);
    printf("栈顶元素 e=%d 栈的长度为%d\n", e, length(s));
	ClearStack(&s);
	printf("清空栈后，栈空否：%d(1:空 0:否)\n",stackempty(s));
	return 0;
}
