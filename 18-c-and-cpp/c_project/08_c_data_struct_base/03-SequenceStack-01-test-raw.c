/*
1.˳��ջ��ʹ�����龲̬�����ڴ�.
2.ջ��λ�ó�ʼ��ֵΪ-1.
*/
#include<stdio.h>
#include<stdbool.h>					//bool���������͵�ͷ�ļ���
//#include<string.h>
#define maxsize 20				//���������СΪ20

typedef int elementype;		//int���ͱ���

typedef struct node{
	elementype data[maxsize];			//������
	elementype top;						//ջ��ָ��
}myStack;

void visit(elementype c)			//����ջ�е�Ԫ��
{
	printf("%d ", c);
}

bool initstack(myStack *s)			//��ʼ��ջ
{
	//����û�и�data����ռ佨Ӧ������Ϊ����Ĵ�С�Ѿ��������
	s -> top = -1;//ջ��λ�ó�ʼ��ֵΪ-1
	return true;
}

bool stackempty(myStack s)			//�ж�ջ�Ƿ�Ϊ��
{
	if(s.top == -1)
		return true;
	else
		return false;
}

bool ClearStack(myStack *s) 		//��ջ���
{
        s -> top = -1;
        return true;
}

elementype length(myStack s)		//����ջ��Ԫ�صĸ���
{
	return s.top + 1;
}

bool getTop(myStack s, elementype *e)	//���ջ��Ԫ��
{
	if(s.top == -1)
		return false;
	else
		*e = s.data[s.top];
	return true;
}

bool push(myStack *s, elementype e)			//Ԫ��e��ջ
{
	if(s -> top == maxsize - 1)
		return false;
	else
	{
		s -> top++;				//ջ��ָ���һ
		s -> data[s -> top] = e;		//�²����Ԫ�ؽ�ջ
		return true;
	 }
}

void traverse(myStack s)		//����ջ��Ԫ�ز����д�ӡ
{
	int i = 0;
	while(i <= s.top)
		visit(s.data[i++]);
	printf("\n");
}

bool pop(myStack *s, elementype *e)		//ջ��Ԫ�س�ջ
{
	if(s -> top == -1)
		return false;
	else
	{
		*e = s -> data[s -> top];
		s -> top--;			//ջ��ָ���һ
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
	puts("��ջ֮���Ԫ������Ϊ�� ");
	traverse(s);

	pop(&s, &e);
	printf("������ջ��Ԫ��Ϊ %d \n", e);
	printf("����ջ��Ԫ��֮���ջ�Ƿ�Ϊ��(1:�� 0:��)%d\n", stackempty(s));
    getTop(s, &e);
    printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n", e, length(s));
	ClearStack(&s);
	printf("���ջ��ջ�շ�%d(1:�� 0:��)\n",stackempty(s));
	return 0;
}
