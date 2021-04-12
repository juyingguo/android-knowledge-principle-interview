/*
1.顺序栈，使用指针动态分配内存.
2.栈顶位置初始化值为-1.
*/
#include<stdio.h>
#include<stdbool.h>					//bool（布尔类型的头文件）
#include<stdlib.h>
#define CAPACITY 3 //容量
typedef struct
{
    int *m_pHead; //指向数组头
    int m_iTop; //栈顶
    int m_iCapacity; //容量
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
        printf("动态内存分配失败!\n");
        return pStack;
    }

    pStack->m_pHead = (int*)malloc(sizeof(int) * CAPACITY);
    if(!pStack->m_pHead)
    {
        printf("动态内存分配失败!\n");
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
        printf("顺序栈不存在!\n");
        return false;
    }

    if(pStack->m_iTop == pStack->m_iCapacity - 1)
    {
        printf("顺序栈已满!\n");
        return false;
    }

    pStack->m_pHead[++pStack->m_iTop] = iElement;
    return true;
}

int pop(SStack *pStack)
{
    if(!pStack || !pStack->m_pHead)
    {
        printf("顺序栈不存在!\n");
        return -1;
    }

    if(pStack->m_iTop < 0)
    {
        printf("顺序栈元素个数为0!\n");
        return -1;
    }

    return pStack->m_pHead[pStack->m_iTop--];
}
void showStack(SStack *pStack)
{
    if(!pStack || !pStack->m_pHead)
    {
        printf("顺序栈不存在!\n");
        return;
    }

    printf("容量：%d，栈顶：%d，打印元素：\n", pStack->m_iCapacity, pStack->m_iTop);
    for(int i = 0; i <= pStack->m_iTop; i++)
        printf("%d ", pStack->m_pHead[i]);

    printf("\n");
}

void releaseMem(SStack* pStack)
{
    if(!pStack)
    {
        printf("顺序栈不存在!\n");
        return;
    }

    if(pStack->m_pHead)
        free(pStack->m_pHead);

    free(pStack);
    printf("内存释放成功!\n");
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
