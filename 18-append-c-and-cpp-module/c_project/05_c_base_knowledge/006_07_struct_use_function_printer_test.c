//14.2.2 C���Խṹ���ж��庯��ָ�����
//			�����ʲ��͡���linux,Ƕ��ʽ��������
//			https://blog.csdn.net/qq_21792169/article/details/50436089

#include <stdio.h> /* ��׼�������ͷ�ļ� */
#include <stdlib.h> /* strtoul�õ���ͷ�ļ�*/


struct test_pfun { /* ����һ���ṹ�壬������������Ա������������ָ�� ,ǰ��ǧ��Ҫ��static,���ﲢû�з����ڴ�*/
	int (*add) (int a,int b); 
	int (*sub) (int a,int b);
	int (*mult) (int a,int b);
};

static int test_add(int a,int b)  /* ������ͺ��� */
{
 	return (a+b);
}

static int test_sub(int a,int b)  /* ����������� */
{
 	return (a-b);
}

static int  test_mult(int a,int b)  /* ����˷����� */
{
 	return (a*b);
}


struct test_pfun pfun={  /* �ؼ��ĵط�ʱ���������ô����ָ�븳ֵ */
.add  =test_add,
.sub  =test_sub,
.mult =test_mult,
};

int main(void)
{
	 int a = 10 ,b = 20; 

	/* ����strtoul������������������ */

	printf("a+b=%d\n",pfun.add(a,b));
	printf("a-b=%d\n",pfun.sub(a,b));
	printf("a*b=%d\n",pfun.mult(a,b));
 	return 0;
}
