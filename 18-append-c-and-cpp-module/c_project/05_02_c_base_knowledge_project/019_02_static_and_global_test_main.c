#include <stdio.h>
#include "head_test.h"
//#define DEVICE_NAME
//DEVICE_NAME 在头文件中head_test.h定义，当引入头文件时，#ifdef DEVICE_NAME为true。
#ifdef DEVICE_NAME
#define DEBUG
#endif // DEVICE_NAME

int main(void)
{

    extern char a; // extern variable must be declared before use
    #ifdef DEBUG
     printf("%c ", a);
     #endif // DEBUG
     (void)msg();
     return 0;
}
