#include <stdio.h>
int main(void)
{

    int *p = NULL;
    if(p == NULL){
        printf("p == NULL\n");
    }

    if(!p){
         printf("p == NULL\n");
    }

    return 0;
}
