/**
题目：时间函数举例2
*/

//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015年 菜鸟教程. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    long i=10000000L;
    clock_t start,finish;
    double TheTimes;
    printf("做%ld次空循环需要的时间为",i);
    start=clock();
    while(i--);
    finish=clock();
    TheTimes=(double)(finish-start)/CLOCKS_PER_SEC;
    printf("%f秒。\n",TheTimes);
    return 0;
}



