#include <stdio.h>
#include "head_test.h"
//#define DEVICE_NAME
//DEVICE_NAME ��ͷ�ļ���head_test.h���壬������ͷ�ļ�ʱ��#ifdef DEVICE_NAMEΪtrue��
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
