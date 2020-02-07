#include<stdio.h>
#include<string.h>
 
void main(){
    char str[] = "hello world";
	int len = strlen(str),i;
	for (i = 0; i < len; i++) {
		printf("%c", str[i]);
	}
	printf("\n");
	char *p = str;
	for (i = 0; i < len; i++) {
		printf("%c", *(p++));
	}
    printf("\n");
    for (i = 0; i < len; i++) {
		printf("%c", *(str+i));
	}
	
	p = str; //再次输出，需要重新指向首地址，因为上面程序执行后已经指向了了字符串末尾了。 
	printf("使用指针直接输出整个字符串 \n");
	printf("%s \n", p);
	
	system("pause");
}
