/**
��Ŀ��Ҫ����������������̡�

�����������������������64���ڰ����ĸ�����ɣ���Ϊ8��*8�С���i�����У�j�������У�����i+j�ĺ͵ı仯����������ڷ��񣬻��ǰ׷���

����������������ο������͡�C ��ϰʵ��7���Ľ��������
*/

//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015�� ����̳�. All rights reserved.
//
 
#include<stdio.h>
 
int main()
{
    int i,j;
    int flag = 219; 
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            if((i+j)%2==0)
                printf("%c%c",flag,flag);
            else printf("  ");
        printf("\n");
    }
    return 0;
}
