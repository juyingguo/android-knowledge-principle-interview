#include <stdio.h>
#include <string.h>

int main( )
{
    int a = 1;
    int b = 20;
    int *p1 = &a;
    int *p2 = p1;

    printf("p1 = %x ,p2 = %x\n",p1,p2);

//    *p1 = 100;//这样写不行的。因为需要只用变量，指针指向变量的指针。要赋值，必须要有变量
//    p1 = &a;
    p2 = &b;
    *p2 = 100;

    printf("p1 = %x ,p2 = %x\n",p1,p2);
    printf("*p1 = %d ,*p2 = %d\n",*p1,*p2);

   return 0;
}
