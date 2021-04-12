/*
1.顺序栈，使用指针动态分配内存.
2.栈顶位置初始化值为0.
    注意：初始化可以为 0 or -1 .这里初始化的不同会导致后面判断栈空和栈满的不同
*/
#include<stdio.h>
#include<stdlib.h>
//顺序栈
struct Stack{
 int *data;     //用指针动态分配内存
 int capacity;  //容量
 int top;       //栈顶元素
};

void init(struct Stack *ps,int capacity){  //初始化栈
 ps->capacity = capacity;
 ps->data = (int *)malloc(sizeof(capacity));
 ps->top = 0;     //初始化可以为 0 or -1 .这里初始化的不同会导致后面判断栈空和栈满的不同
} //top=0 表示top始终指向最高元素之上的空格  因此栈满时下标是0~capacity-1
    //top=-1 表示top始终指向最高元素

int isFull(const struct Stack *ps){ //判断栈是否已满
 return ps->top == ps->capacity;
}

 int isEmpty(const struct Stack *ps){    //判断栈是否为空
    return ps->top == 0;
}

int push(struct Stack *ps,int x){    //压栈
 if(isFull(ps)) return 0;
 else{
  ps->data[ps->top] = x;
  ps->top++;
  return 1; //压栈成功
 }
}

int pop(struct Stack *ps,int *px){ //弹栈，并将栈顶元素返回给*px
 if(isEmpty(ps)) return 0;
 else{
  ps->top--;
  *px = ps->data[ps->top];
  return 1; //弹栈成功
 }
}

void destory(struct Stack *ps){    //好习惯，使用完栈，将分配的空间释放,以防日后需要多次使用
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


