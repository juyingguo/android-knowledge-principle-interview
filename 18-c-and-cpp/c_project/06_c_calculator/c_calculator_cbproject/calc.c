#include<stdio.h>
#include<stdlib.h>

/*
This is the main method
It's the entry point of our program
*/
int main(int argc, char* argv[]){
	int argv1, argv2;
	printf("Calculator\n\n");
	printf("number of arguments passed: %d\n", argc);
	printf("first argument: %s\n", argv[0]);
	if(argc>1){
		if(argc>=3){
            //C �⺯�� int atoi(const char *str) �Ѳ��� str ��ָ����ַ���ת��Ϊһ������������Ϊ int �ͣ���
            argv1 = atoi(argv[1]);
            argv2 = atoi(argv[2]);
            printf("The sum of argv[1] and argv[2]: %d\n", add(argv1, argv2));
            printf("The subtract of argv[1] and argv[2]: %d\n", subs(argv1, argv2));
            printf("The multiply of argv[1] and argv[2]: %d\n", prod(argv1, argv2));
            printf("The divide of argv[1] and argv[2]: %d\n", divid(argv1, argv2));
		}
	}
	return 0;
}









