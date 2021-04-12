#include<stdio.h>
#include<stdlib.h>

//"12345"   12345
//12345    "12345"

int  tonum(char *str)//-1代表失败
{

	char *istr = str;//保留副本
	int num=0;
	while (*str != '\0')
	{

		if ((*str)<'0' || (*str)>'9')
		{
            printf("str contain not [0-9] char,can not convert to integer.\n");
			return  -1;
		}
	    printf("%c\n", *(str++));//取出每一个字符
//		*str++;
//		*(str ++);
		num++;//计数，判断有多少位
	}
	printf("num = %d \n", num);
	int lastres = 0;   //12345  1  12  123 1234 12345
	for (int i = 0; i < num; i++)
	{
		lastres *= 10;   //结果乘以10
		int wei = istr[i] - 48;//取出字符
        printf("istr[%d] = %d \n",i, istr[i]);//取出每一个字符
		lastres += wei;//累加
		printf("wei=%d \n", wei);//打印字符转换为整数的位
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
	printf("%d,%c \n", 1, 1);//1,编号为1的字符
	printf("\n%d,%c \n", '1', '1');//‘1’的编号49,‘1’
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
	//6543210  对应存入数组
	for (int i = wei - 1; num; num /= 10, i--)
	{
		str[i] = num % 10 + 48;//整数+48，整数编号
		printf("%d,%d \n", num % 10,i);
	}

}

void  main()
{
	int num = 1234567;
	char str[10] = { 0 };//编号为0的字符
	tostr(num, str);
	printf("%s \n", str);

	getchar();




}
