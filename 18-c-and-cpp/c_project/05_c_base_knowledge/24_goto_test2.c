#include <stdio.h>
int main(void)
{

    int *p = NULL;
    if(p == NULL){
        printf("p == NULL\n");
        goto  mynull;
    }

    if(!p){
         printf("p == NULL\n");
    }
    mynull:
             printf("mynull,p == NULL\n");
             printf("mynull,p == NULL\n");
    return 0;
}
