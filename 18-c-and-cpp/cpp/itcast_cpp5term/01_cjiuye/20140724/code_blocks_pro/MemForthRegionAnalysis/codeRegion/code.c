#include<stdio.h>
#include<stdlib.h>


void gogogo()
{

	printf("AAAAA\n\n\n\n");
}

void main()
{
	printf("%p", gogogo);//��������ź����ĵ�ַ
	//gogogo = gogogo;������ֻ�ܶ�����д
	//void gogogo()��
	//void ()();
//	gogogo();//ֱ�ӵ���

//	void(*p)()=gogogo;
//	p();//��ӵ���


	getchar();

}


void    main2()
{
	char *p = "ABCDEFG";//p�洢�����ַ����ĵ�ַ
	printf("%d,%d\n", sizeof(p), sizeof("ABCDEFG"));
	printf("\n%p", &p);//�鿴ָ������ĵ�ַ
	printf("\n%p", p);//�鿴�ַ����ĵ�ַ
	*p = 'a';//������ֻ�ܶ��������ַ����ڴ�����


	getchar();






}
