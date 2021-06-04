/**
创建一个字符指针p指向一个数组，再创建字符指针n指向p,cpp中可以通过操作n,达到给p指向的数组赋值。而该功能能够通过c实现吗？

*/
#include<stdio.h>
#include<string.h>

int main(){
    char *p = "abc";
	char x = 'x',y = 'y',z = 'z';

//    char *p = new char[3];
	int len = strlen(p);
    printf("len = %d\n", len);

    char *data[3] = {0};
    data[0] = p;

//    *p = x;
//    *(p+1) = y;
//    *(p+2) = z;


//    printf("*p=%c\n", *p);
//    printf("p=%s\n", p);
    int i;
//	for (i = 0; i < len; i++) {
//		printf("%c\n", *(p++));
//	}
//
//    printf("*data[0]=%c\n", *data[0]);
//    printf("*(data[0] + 1)=%c\n", *(data[0] + 1));
//    printf("*(data[0] + 2)=%c\n", *(data[0] + 2));

    *data[0] = 'm';
//    *(data[0] + 1) = 'n';
//    *(data[0] + 2) = 't';
//    (data[0] + 1) = &y;
//    (data[0] + 2) = &z;
//    for (i = 0; i < len; i++) {
//		printf("%c\n", *(p++));
//	}
    for (i = 0; i < len; i++) {
		printf("%c\n", *(p++));
	}
	system("pause");
	return 0;
}
