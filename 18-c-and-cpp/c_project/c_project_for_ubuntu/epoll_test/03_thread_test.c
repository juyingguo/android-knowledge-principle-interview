#include<stdio.h>
#include <pthread.h>
void *ThreadFunc(void *pArg)  //参数的值为123

{

int i = 0;

int *prt = (int *)pArg;

for(; i<10; i++)

{

       printf("Hi,I'm child thread,arg is:%p\n",pArg);

       sleep(1);

}

pthread_exit(NULL);

}

int main()

{

    pthread_t thdId;
    pthread_create(&thdId, NULL, ThreadFunc,(int*) 123 );

    int i = 0;
    for(; i<10; i++)

        {

            printf("Hi,I'm main thread,child thread id is:%x\n", (unsigned int)thdId);

              sleep(1);

         }

         return 0;

}
