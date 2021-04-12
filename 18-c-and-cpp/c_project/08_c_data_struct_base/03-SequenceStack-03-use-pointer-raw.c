/*
1.˳��ջ��ʹ��ָ�붯̬�����ڴ�.
2.ջ��λ�ó�ʼ��ֵΪ0.
    ע�⣺��ʼ������Ϊ 0 or -1 .�����ʼ���Ĳ�ͬ�ᵼ�º����ж�ջ�պ�ջ���Ĳ�ͬ
*/
#include<stdio.h>
#include<stdlib.h>
//˳��ջ
struct Stack{
 int *data;     //��ָ�붯̬�����ڴ�
 int capacity;  //����
 int top;       //ջ��Ԫ��
};

void init(struct Stack *ps,int capacity){  //��ʼ��ջ
 ps->capacity = capacity;
 ps->data = (int *)malloc(sizeof(capacity));
 ps->top = 0;     //��ʼ������Ϊ 0 or -1 .�����ʼ���Ĳ�ͬ�ᵼ�º����ж�ջ�պ�ջ���Ĳ�ͬ
} //top=0 ��ʾtopʼ��ָ�����Ԫ��֮�ϵĿո�  ���ջ��ʱ�±���0~capacity-1
    //top=-1 ��ʾtopʼ��ָ�����Ԫ��

int isFull(const struct Stack *ps){ //�ж�ջ�Ƿ�����
 return ps->top == ps->capacity;
}

 int isEmpty(const struct Stack *ps){    //�ж�ջ�Ƿ�Ϊ��
    return ps->top == 0;
}

int push(struct Stack *ps,int x){    //ѹջ
 if(isFull(ps)) return 0;
 else{
  ps->data[ps->top] = x;
  ps->top++;
  return 1; //ѹջ�ɹ�
 }
}

int pop(struct Stack *ps,int *px){ //��ջ������ջ��Ԫ�ط��ظ�*px
 if(isEmpty(ps)) return 0;
 else{
  ps->top--;
  *px = ps->data[ps->top];
  return 1; //��ջ�ɹ�
 }
}

void destory(struct Stack *ps){    //��ϰ�ߣ�ʹ����ջ��������Ŀռ��ͷ�,�Է��պ���Ҫ���ʹ��
 free(ps->data);
}

int main()
{
  struct Stack st;
  init(&st,5);
  push(&st,11);
  push(&st,22);
  push(&st,33);
  push(&st,44);
  push(&st,55);
  push(&st,66);
  int x;
  pop(&st,&x);
  printf("%d\n",x);
  destory(&st);

 return 0;
}


