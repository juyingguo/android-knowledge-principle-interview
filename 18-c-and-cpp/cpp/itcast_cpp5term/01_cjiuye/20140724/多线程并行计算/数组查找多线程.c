#define  _CRT_SECURE_NO_WARNINGS//�رհ�ȫ���
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>


void gogogo(void *p)
{
	int *px = (int*)p;//ָ��ת��


	//return ; //�߳�ִ������Ժ󷵻�
	int i = 0;
	while (1)
	{
		if (i > 5)
		{
			printf("%d   %d\n", i,*px);
			_endthread();//�����߳�
		}
		Sleep(1000);
		i++;

	}

}

void  time(void *p)
{
	int i = 0;
	while (1)
	{

		char str[100] = { 0 };
		sprintf(str, "title ��ǰʱ���%d��", i);
		system(str);
		i++;
		Sleep(1000);
	}
}


void main()
{
	//time(NULL);
	_beginthread(time, 0, NULL);

	for (int i = 0; i < 5; i++)
	{
		//gogogo(NULL);
		HANDLE  hd = _beginthread(gogogo, 0, &i);//hd�Ǳ��
		WaitForSingleObject(hd, INFINITE);//�ȴ�,����ģʽ  ��û��wait����ģʽ
		Sleep(1000);
	}

	getchar();




}
