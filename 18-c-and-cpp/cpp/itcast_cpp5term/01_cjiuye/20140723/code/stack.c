#include<stdio.h>
#include<stdlib.h>

#define N  50
struct mystack
{
	int top;//ջ��
	int data[N];//�������
};
struct mystack  selfstack = { -1, {0} };//ջ�ĳ�ʼ��

int is_empty();//1 Ϊ�� 0 �ǿ�
void setempty();//ջ����Ϊ��
int  push(int num);//ѹ������ ���ɹ�1��ʧ�ܷ���0
int pop();//��������

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
	selfstack.top = -1;//����ջΪ��
}

int  push(int num)
{
	if (selfstack.top == N - 1)//ջ���
	{
		return 0;//ʧ��
	}
	else
	{
		selfstack.top += 1;//�±��ƶ�һ��
		selfstack.data[selfstack.top] = num;//ѹ������
		return 1;
	}
}

int pop()
{
	if (selfstack.top == -1)
	{
		return -1;//ջΪ��
	}
	else
	{
		selfstack.top -= 1;
		return selfstack.data[selfstack.top + 1];//���ص���������
	}




}

void  main22()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 10; i++)
	{
		push(a[i]);//�������
	}
	while (!is_empty())
	{
		printf("%d\n", pop());//�������
	}




	system("pause");
}

void main()
{
	int num = 10;

	while (num)
	{
		push(num % 2);//ѹ������
		num /= 2;//ѭ��

	}
	while (!is_empty())
	{
		printf("%d", pop());//�������
	}


	system("pause");


}
