#include<stdio.h>
#include<stdlib.h>
int main()
{   /**
    �ܱ�400����,���ܱ�4�������Ҳ��ܱ�100������������
			����Ķ���������
    */
	int year;
	printf("��������ݣ�");
//	scanf_s("%d", &year);
	scanf("%d", &year);
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		printf("%d������\n",year);
	else
		printf("%d��������\n",year);
    system("pause");
	return 0;
}
