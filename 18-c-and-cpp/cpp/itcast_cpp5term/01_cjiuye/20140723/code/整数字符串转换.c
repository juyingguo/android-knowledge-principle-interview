#include<stdio.h>
#include<stdlib.h>

//"12345"   12345
//12345    "12345"

int  tonum(char *str)//-1����ʧ��
{

	char *istr = str;//��������
	int num=0;
	while (*str != '\0')
	{

		if ((*str)<'0' || (*str)>'9')
		{
            printf("str contain not [0-9] char,can not convert to integer.\n");
			return  -1;
		}
	    printf("%c\n", *(str++));//ȡ��ÿһ���ַ�
//		*str++;
//		*(str ++);
		num++;//�������ж��ж���λ
	}
	printf("num = %d \n", num);
	int lastres = 0;   //12345  1  12  123 1234 12345
	for (int i = 0; i < num; i++)
	{
		lastres *= 10;   //�������10
		int wei = istr[i] - 48;//ȡ���ַ�
        printf("istr[%d] = %d \n",i, istr[i]);//ȡ��ÿһ���ַ�
		lastres += wei;//�ۼ�
		printf("wei=%d \n", wei);//��ӡ�ַ�ת��Ϊ������λ
	}
	return  lastres;

}

void  main2()
{

	char str[10] = "1234567";
	int num = 0;
	printf("\n%d \n", tonum(str));





	system("pause");
}

void  main3()
{
	printf("%d,%c \n", 1, 1);//1,���Ϊ1���ַ�
	printf("\n%d,%c \n", '1', '1');//��1���ı��49,��1��
	printf("%d \n", '1' - 1);
	system("pause \n");
}

void tostr(int num,char *str)
{
	int wei = 0;
	for (int inum = num; inum; inum /= 10)
	{
		wei++;
	}
	//printf("wei=%d\n", wei);
	//6543210  ��Ӧ��������
	for (int i = wei - 1; num; num /= 10, i--)
	{
		str[i] = num % 10 + 48;//����+48���������
		printf("%d,%d \n", num % 10,i);
	}

}

void  main()
{
	int num = 1234567;
	char str[10] = { 0 };//���Ϊ0���ַ�
	tostr(num, str);
	printf("%s \n", str);

	getchar();




}
