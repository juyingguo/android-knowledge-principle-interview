/**
��Ŀ�����9*9�ھ���
*/

#include<stdio.h>
int main()
{
	int i,j,result;
    printf("\n");
    for (i=1;i<10;i++)
    {
        for(j=1;j<=i;j++)
        {
            result=i*j;
            printf("%d*%d=%-5d",i,j,result); /*-3d��ʾ����룬ռ3λ*/
        }
    	printf("\n"); /*ÿһ�к���*/
    }
   
    return 0;
}
