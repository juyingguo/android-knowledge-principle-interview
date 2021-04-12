
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char name[5];
    printf("input name\n");
//	scanf("%s", name);//%5s指定宽度为5。如果不指定，超过五个，虽然能够打印，但控制台也会异常退出。
	scanf("%5s", name);//%5s指定宽度为5。如果不指定，超过五个，虽然能够打印，但控制台也会异常退出。
	printf("%s\n",name);
//	scanf_s("%s", name);
	return 0;
}
