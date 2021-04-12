/**
题目：打印楼梯，同时在楼梯上方打印两个笑脸。

程序分析：用 ASCII 1 来输出笑脸；用i控制行，j来控制列，j根据i的变化来控制输出黑方格的个数。

如果出现乱码情况请参考【C 练习实例7】的解决方法。
*/
//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015年 菜鸟教程. All rights reserved.
//
 
#include<stdio.h>
 
int main()
{
    int i,j;
    printf("\1\1\n"); /*输出两个笑脸*/
    printf("%c%c\n",1,1); /*输出两个笑脸*/
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
