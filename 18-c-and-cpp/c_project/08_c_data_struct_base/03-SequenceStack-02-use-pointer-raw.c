/*
1.˳��ջ��ʹ��ָ�붯̬�����ڴ�.
2.ջ��λ�ó�ʼ��ֵΪ-1.
*/
#include<stdio.h>
#include<stdbool.h>					//bool���������͵�ͷ�ļ���
#include<stdlib.h>
#define CAPACITY 3 //����
typedef struct
{
    int *m_pHead; //ָ������ͷ
    int m_iTop; //ջ��
    int m_iCapacity; //����
}SStack;

SStack* createStack();
bool push(SStack *pStack, int iElement);
int pop(SStack *pStack);
void showStack(SStack *pStack);
void releaseMem(SStack* pStack);

SStack* createStack()
{
    SStack *pStack = (SStack*)malloc(sizeof(SStack));
    if(!pStack)
    {
        printf("��̬�ڴ����ʧ��!\n");
        return pStack;
    }

    pStack->m_pHead = (int*)malloc(sizeof(int) * CAPACITY);
    if(!pStack->m_pHead)
    {
        printf("��̬�ڴ����ʧ��!\n");
        return NULL;
    }

    pStack->m_iTop = -1;
    pStack->m_iCapacity = CAPACITY;

    return pStack;
}
bool push(SStack *pStack, int iElement)
{
    if(!pStack || !pStack->m_pHead)
    {
        printf("˳��ջ������!\n");
        return false;
    }

    if(pStack->m_iTop == pStack->m_iCapacity - 1)
    {
        printf("˳��ջ����!\n");
        return false;
    }

    pStack->m_pHead[++pStack->m_iTop] = iElement;
    return true;
}

int pop(SStack *pStack)
{
    if(!pStack || !pStack->m_pHead)
    {
        printf("˳��ջ������!\n");
        return -1;
    }

    if(pStack->m_iTop < 0)
    {
        printf("˳��ջԪ�ظ���Ϊ0!\n");
        return -1;
    }

    return pStack->m_pHead[pStack->m_iTop--];
}
void showStack(SStack *pStack)
{
    if(!pStack || !pStack->m_pHead)
    {
        printf("˳��ջ������!\n");
        return;
    }

    printf("������%d��ջ����%d����ӡԪ�أ�\n", pStack->m_iCapacity, pStack->m_iTop);
    for(int i = 0; i <= pStack->m_iTop; i++)
        printf("%d ", pStack->m_pHead[i]);

    printf("\n");
}

void releaseMem(SStack* pStack)
{
    if(!pStack)
    {
        printf("˳��ջ������!\n");
        return;
    }

    if(pStack->m_pHead)
        free(pStack->m_pHead);

    free(pStack);
    printf("�ڴ��ͷųɹ�!\n");
}

int main()
{
	SStack * stack = createStack();
	push(stack,10);
	push(stack,50);
	push(stack,20);
	push(stack,80);

	showStack(stack);

    int pop_value = pop(stack);
    printf("main,pop_value = %d!\n",pop_value);
    pop(stack);
    showStack(stack);
	return 0;
}
