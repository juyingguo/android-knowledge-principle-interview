#include <stdio.h>
//#include "head_test.h"
//#define DEVICE_NAME
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
