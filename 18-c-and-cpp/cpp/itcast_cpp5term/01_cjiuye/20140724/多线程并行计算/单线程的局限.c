#include <stdio.h>
#include<Windows.h>
#include<process.h>//����
#include<stdlib.h>

struct MyStruct
{
	int num;
	double data;
};


void  run(void *p)
{
	int *px = (int *)p;//ָ��ת��
	//printf("�߳�%d����", *px);
	char str[100] = {0};//�ַ�����
	sprintf(str, "�߳�%d����", *px);

	MessageBoxA(0,str, "���߳�", 0);
}


void main()
{

	for (int i = 0; i < 5; i++)
	{
		//run(NULL);
		_beginthread(run, 0, &i);

		Sleep(10);
	}



	system("pause");

}
