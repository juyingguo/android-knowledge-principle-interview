#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<Windows.h>

int  flag = 0;//��ζ��û���ҵ�
int  * addrfind = NULL;//��ַ
struct MyStruct
{
	int *pfindstart;//Ҫ���ҵ��׵�ַ
	int  length;//�޶����ȣ��ӵ�ַ��ʼ
	int  num;//Ҫ���ҵ�����
	int  bh;//���
	int  *pflag;//����flag�ĵ�ַ���޸�flag,����
	int **addr;//����һ��ָ��ĵ�ַ��
};



void find(void *p)
{
	struct MyStruct *pstruct = (struct MyStruct *)p;//ָ������ת��
	//�ڴ�ı������ӵ�ַ��ʼ�ۼ�100��Ԫ�صĴ�С����������Ԫ��
	for (int *px = pstruct->pfindstart; px < pstruct->pfindstart + 100; px++)
	{
		Sleep(100);
		if (*(pstruct->pflag) != 0)
		{
			printf("����%d���ܣ������߳��Ѿ��ҵ� \n", pstruct->bh);
			return;
		}

		if (*px == pstruct->num)//�ж��Ƿ����
		{
			printf("\n��%d���߳��ҵ�%p,%d \n",pstruct->bh, px,*px);//����
			*(pstruct->pflag) = 1;//�ı��ʶ�������ҵ�
			*(pstruct->addr) = px;
			return;
		}

	}
	printf("\nû���ҵ���%d���߳�\n", pstruct->bh);

	return;


}

void main()
{
	int a[1000];//783;����
	for (int i = 0; i < 1000; i++)
	{
		a[i] = i;//�����ʼ��
	}
	struct MyStruct threaddata[10];//�����ṹ��,����ͬ���̣߳�
	for (int i = 0; i < 10; i++)//����10���̲߳��в���
	{
		//a , a+100 a+200               a+900


		threaddata[i].pfindstart  = a + i * 100;//��������ĵ�ַ
		threaddata[i].length = 100;//����
		threaddata[i].bh = i;//���
		threaddata[i].num = 783;//Ҫ���ҵ�����
		threaddata[i].pflag = &flag;//��ʶ
		threaddata[i].addr = &addrfind;//�洢�˱����ĵ�ַ


		printf("\n%d\n", threaddata[i].bh);
		_beginthread(find, 0, &threaddata[i]);//

		//Sleep(30);///
	}



	Sleep(30000);


	system("pause");
	printf("\n\n%d,%p\n\n", *addrfind, addrfind);//��ӡ��ַ����������
	system("pause");
}
