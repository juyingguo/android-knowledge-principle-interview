
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char name[5];
    printf("input name\n");
//	scanf("%s", name);//%5sָ�����Ϊ5�������ָ���������������Ȼ�ܹ���ӡ��������̨Ҳ���쳣�˳���
	scanf("%5s", name);//%5sָ�����Ϊ5�������ָ���������������Ȼ�ܹ���ӡ��������̨Ҳ���쳣�˳���
	printf("%s\n",name);
//	scanf_s("%s", name);
	return 0;
}
