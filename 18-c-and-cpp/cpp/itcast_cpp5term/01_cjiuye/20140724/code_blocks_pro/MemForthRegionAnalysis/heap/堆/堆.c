#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>



//�ڴ���䣬malloc calloc,realloc
void  test()
{
	int *p = (int *)malloc(sizeof(int)* 10);//ָ����˵�ַ�����ͣ�
	printf("%p\n", p);//��ӡ��ַ

	int num = 0;
	for (int *px = p; px < p + 10; px++)
	{


		*px = num;//�����ݸ�ֵ

		printf("%p,%d\n", px, *px);//��ӡ��ַ��������
		num++;

	}



}

void mainA()
{

	test();
	test();


	system("pause");








}

void mainB()
{

	unsigned  long long ll = 1024 * 1024 * 1024;//ll   2^64-1  ����
	ll *= 1;
	void *p = malloc(1024 * 1024);
	if (p == NULL)
	{
		printf("�ڴ����ʧ��\n");
	}
	else
	{
		printf("�ɹ�\n");
	}


	system("pause");
}

void   main()
{
	while (1)
	{
		//�ڴ�һ��Ҫ��ʱ�ͷ�
		void *p = malloc(100*1024*1024);//p, ջ    *(p+3)��ַָ�������
		if (p == NULL)
        {
            printf("�ڴ����ʧ��\n");
        }
        else
        {
            printf("�ɹ�\n");
        }
		Sleep(100);
//		free(p);//�ͷ��ڴ�
//		Sleep(3000);

	}


}
