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
	
	p = str; //�ٴ��������Ҫ����ָ���׵�ַ����Ϊ�������ִ�к��Ѿ�ָ�������ַ���ĩβ�ˡ� 
	printf("ʹ��ָ��ֱ����������ַ��� \n");
	printf("%s \n", p);
	
	system("pause");
}
