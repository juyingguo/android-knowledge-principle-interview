/**
题目：要求输出国际象棋棋盘。

程序分析：国际象棋棋盘由64个黑白相间的格子组成，分为8行*8列。用i控制行，j来控制列，根据i+j的和的变化来控制输出黑方格，还是白方格。

如果出现乱码情况请参考本博客【C 练习实例7】的解决方法。
*/

//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015年 菜鸟教程. All rights reserved.
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
