/**
��Ŀ�������ַ������Ӵ����ֵĴ��� ��
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{ 
    int i,j,k,TLen,PLen,count=0;
    char T[50],P[10];
    printf("�����������ַ������Իس�������ĸ����ǰ���Ӵ��ں�\n");
    gets(T);
    gets(P);
    TLen=strlen(T);
    PLen=strlen(P);
    for(i=0;i<=TLen-PLen;i++)
    {
        for(j=0,k=i;j<PLen&&P[j]==T[k];j++,k++);
        
        if(j==PLen)count++;
        
    }
    printf("%d\n",count);
    system("pause");
    return 0;
}
