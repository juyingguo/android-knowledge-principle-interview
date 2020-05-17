#include <stdio.h>

/*
    signed char [-128,+127]  --? [-127,128]


*/
void foo(void)
{
   unsigned int a = 6;
   int b = -20;
   (a+b > 6)?puts("> 6") : puts("<= 6");
}

void dis8bit(char val)
{
    int bit=8;
    while(bit--){
        if(1<<bit& val){
            printf("1");
        }else{
            printf("0");
        }
        if(!(bit%4))
            printf(" ");
    }
    putchar(10);
}
void dis32bit(int val)
{
    int bit=32;
    while(bit--){
        if(1<<bit& val){
            printf("1");
        }else{
            printf("0");
        }
        if(!(bit%4))
            printf(" ");
    }
    putchar(10);
}
int main(void)
{
//    char a = -1,b = 0,c = -128,d = 127;
//    dis8bit(a);
//    dis8bit(b);
//    dis8bit(c);
//    dis8bit(d);
//    int e = -1;
//    dis32bit(e);

//    int a = 511;
//    dis32bit(a);
//    char b = a;
//    dis8bit(b);
//    printf("b = %d\n",b);

//    unsigned char a = 255;
//    dis8bit(a);
//    int b = a;
//    dis32bit(b);
//    printf("%d\n",b);


    char a = -20;
    dis8bit(a);
    unsigned int b = 1;
    dis32bit(b);

    unsigned int c = a + b;
    dis32bit(c);

//    printf("%u\n",c);

    foo();

    return 0;
}
//GNU　对其它作的扩充

//do{} while(0);

////#define SAFE_FREE(p) do {free(p); p=NULL;}while(0)
//
//void func()
//{
//    int a;
//}
//
//int main(int argc, char ** argv)
//{
//    func();
//}























