#include <stdio.h>

int main( )
{
     printf("Stdout Helo World!!\n");

    fprintf(stdout,"Stdout Hello World!!\n");

    int a = 1/0;
    perror("Stderr Hello World!!\n");

    fprintf(stderr,"Stderr Hello World!!\n");  //zai linux 下执行，./test > text.txt 会输出到文件。
    return 0;

}
