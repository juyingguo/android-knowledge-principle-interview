#include<stdio.h>
#include<stdlib.h>//Ҫʹ��malloc��Ҫ������ͷ�ļ�
#include <memory.h>//Ҫʹ��memset��Ҫ������ͷ�ļ�
int main()
{
    int m;
    scanf("%d", &m);//scanfֻ�������س�����ʱ���������û�аѻس������룬����������л���һ���س���
    getchar();//���������еĻس�������
    int *p;
    p = (int*)malloc(m*(sizeof(int)));//��̬�����ڴ�
    int *ret = memset(p, 0, m);//��ʼ����ÿ��Ԫ�ض�Ϊ��
    int i;
    for (i=0;i<m; i++)//���鸳ֵ
    {
        p[i] = i;
    }
    for (i = 0; i <m; i++)//��ӡ����
    {
        printf("%p   %d\n",&p[i], p[i]);
    }
    printf("%p\n",p);
     printf("ret = %p\n",ret);
    free(p);//�ͷ��ڴ棬malloc��freeһ��Ҫ�ǵó���ʹ�ã���Ȼ�ᵼ�³�����ڴ�

//    printf("%p   %d\n",&p[0], p[0]);
//    printf("%p   %d\n",&p[1], p[1]);
    getchar();//�ó���ͣ�٣��۲����
    return 0;
}
