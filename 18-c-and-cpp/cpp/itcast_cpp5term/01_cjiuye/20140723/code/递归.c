//#define _CRT_SECURE_NO_WARNINGS  //�رհ�ȫ���

#include<stdio.h>
#include<stdlib.h>


double go(int n)
{
	if (n == 1)
	{
		return 1.0;  //��ֹ
	}
	else if (n==2)
	{
		return 2.0;
	}
	else
	{
		return go(n - 1) + go(n - 2);//�ҳ���ϵ
	}



}

void main3()
{
	//printf("%f", go(50));

	double a[50];
	a[0] = 1;
	a[1] = 2;
	for (int i = 2; i < 50; i++) //�����ѭ����ʵ�ֵݹ�
	{
		a[i] = a[i - 1] + a[i - 2];
		printf("%f\n", a[i]);
	}
	system("pause");
}



/**
�ж�һ�������Ԫ���Ƿ�����ġ��ǵݹ�ʵ�֡�
*/
void main6()
{
	int a[10] = { 1, 4, 3, 4, 5, 6, 7, 8, 9, 10 };
	int flag = 1;//�ٶ��ǵ���
	for (int i = 0; i < 10 - 1; i++)//0-9
	{
		if (a[i] > a[i + 1])//�ǵ���
		{
			flag = 0;//�ǵ���
			break;
		}
	}
	if (flag)
	{
		printf("���� \n");
	}
	else
	{
		printf("fei���� \n");
	}


	system("pause");





}

/**
�ж�һ�������Ԫ���Ƿ�����ġ��ݹ�ʵ�֡�
*/
int  a[10] = { 1, 2, 3, 4, 5, 6, 7, 10, 15, 20 };
int  isadd(int n)   //��������1�����򷵻�0
{
	if (n==8)
	{
		return a[n] < a[n+1];//�ݹ���ֹ
	}
	else
	{
		return  (a[n] < a[n + 1]) && isadd(n + 1); //�����е��жϴ���һ����
	}



}

void  main5()
{
	printf("isadd(0) = %d \n", isadd(0));

	system("pause");

}
/**
�������������С����÷ǵݹ鷽ʽ��12345,54321

*/
void  main()
{
	int num;
	scanf("%d", &num);//��ʼ������
	printf("num=%d \n", num);
	//12345
	int lastres = 0;
	while (num)  // 12345  1234  123   12
	{
		lastres *= 10;     //  0    50     540     5430    54320
		int wei = num % 10; //5     4        3      2       1
		lastres   += wei ; //5     54     543      5432    54321
		num /= 10;  //1234       123      12        1      0

	}
    printf("lastres=%d \n", lastres);

    scanf("%d", &num);//��ʼ������
    printf("daoxuFun(%d)=%d \n", num,daoxuFun(num));
	system("pause");
}
/**
�������������С����õݹ鷽ʽ��12345,54321

*/
int lastres = 0;
int daoxuFun(int num){

    if(num ==0){
        return lastres;
    }else{
        lastres = lastres *10 + num%10;
        return daoxuFun(num/10);
    }
}
