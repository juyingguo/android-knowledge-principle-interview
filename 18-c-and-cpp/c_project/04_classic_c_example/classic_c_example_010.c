/**
��Ŀ����ӡ¥�ݣ�ͬʱ��¥���Ϸ���ӡ����Ц����

����������� ASCII 1 �����Ц������i�����У�j�������У�j����i�ı仯����������ڷ���ĸ�����

����������������ο���C ��ϰʵ��7���Ľ��������
*/
//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015�� ����̳�. All rights reserved.
//
 
#include<stdio.h>
 
int main()
{
    int i,j;
    printf("\1\1\n"); /*�������Ц��*/
    printf("%c%c\n",1,1); /*�������Ц��*/
    for(i=1;i<11;i++)
    {
        for(j=1;j<=i;j++){
        	printf("%c%c",219,219);
            //printf("\219\219");
        }
            
        printf("\n");
    }
    return 0;
}
