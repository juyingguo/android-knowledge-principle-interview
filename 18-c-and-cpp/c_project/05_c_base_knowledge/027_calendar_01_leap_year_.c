#include<stdio.h>
#include<stdlib.h>
int main()
{   /**
    能被400整除,或能被4整除并且不能被100整除的是闰年
			其余的都不是闰年
    */
	int year;
	printf("请输入年份：");
//	scanf_s("%d", &year);
	scanf("%d", &year);
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		printf("%d是闰年\n",year);
	else
		printf("%d不是闰年\n",year);
    system("pause");
	return 0;
}
