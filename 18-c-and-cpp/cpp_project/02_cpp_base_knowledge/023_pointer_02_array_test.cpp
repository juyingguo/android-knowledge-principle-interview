#include<stdio.h>
#include<string.h>

int main(){

    char x = 'x',y = 'y',z = 'z';

    char *p = "abc";
	int len = strlen(p);
    printf("len = %d\n", len);

    char *data[3] = {0};
    data[0] = p;

    printf("*p=%c\n", *p);
    int i;
	for (i = 0; i < len; i++) {
		printf("%c\n", *(p++));
	}

    printf("*data[0]=%c\n", *data[0]);
    printf("*(data[0] + 1)=%c\n", *(data[0] + 1));
    printf("*(data[0] + 2)=%c\n", *(data[0] + 2));

//    data[0] = &x;
//    (data[0] + 1) = &y;
//    (data[0] + 2) = &z;
    for (i = 0; i < len; i++) {
		printf("%c\n", *(p++));
	}

}
