/**
��Ŀ��ʱ�亯������2
*/

//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015�� ����̳�. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    long i=10000000L;
    clock_t start,finish;
    double TheTimes;
    printf("��%ld�ο�ѭ����Ҫ��ʱ��Ϊ",i);
    start=clock();
    while(i--);
    finish=clock();
    TheTimes=(double)(finish-start)/CLOCKS_PER_SEC;
    printf("%f�롣\n",TheTimes);
    return 0;
}



