#include<stdio.h>
#include<stdlib.h>

int  main()
{
    int i = 1;
    if(i == 1){
        goto init;
    }

    while(1)
    {
        printf("in while(1)\n");
        while(i++)
        {
            printf("i = %d\n",i);
            if(i > 3)
            {
                goto TiaoChu;
            }
        }
    }

init :
     printf("init value i = %d\n",i);

TiaoChu:
    printf("program end\n");


    return 0;
}
