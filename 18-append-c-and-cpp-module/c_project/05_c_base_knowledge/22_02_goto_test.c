#include<stdio.h>

void main()
{
    if(1)
    {
        printf("false \n");
        goto gotofalseflag;
    }else{
        printf("true \n");
        goto gototrueflag;
    }
    printf("hello ");
gotofalseflag:printf("nihao\n");
gototrueflag:printf("world\n");

}
