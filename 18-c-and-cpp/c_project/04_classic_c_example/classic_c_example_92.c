/**
��Ŀ��ʱ�亯������2
*/
//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015�� ����̳�. All rights reserved.
//

#include <stdio.h>
#include <time.h>

int main()
{
    time_t start,end;
    int i;
    start=time(NULL);
    for(i=0;i<1000;i++)
    {
        printf("\n");  // ��������time_t�ͱ���֮���ʱ����
    }
    end=time(NULL);
    
    // ���ִ��ʱ��
    printf("ʱ����Ϊ %6f\n",difftime(end,start));
     printf("ʱ����Ϊ %f\n",difftime(end,start));
}
