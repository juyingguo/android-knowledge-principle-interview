/**
题目：时间函数举例2
*/
//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015年 菜鸟教程. All rights reserved.
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
        printf("\n");  // 返回两个time_t型变量之间的时间间隔
    }
    end=time(NULL);
    
    // 输出执行时间
    printf("时间间隔为 %6f\n",difftime(end,start));
     printf("时间间隔为 %f\n",difftime(end,start));
}
