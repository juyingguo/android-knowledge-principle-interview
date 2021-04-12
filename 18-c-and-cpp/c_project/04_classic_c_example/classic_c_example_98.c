//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015年 菜鸟教程. All rights reserved.
//
/**
题目：从键盘输入一个字符串，将小写字母全部转换成大写字母，然后输出到一个磁盘文件"test"中保存。 输入的字符串以！结束。
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int main()
{
    FILE*fp=NULL;
    char str[50];
    int i,len;
    printf("输入一个字符串：\n");
    gets(str);
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]<='z'&&str[i]>='a')
            str[i]-=32;
    }
    if((fp=fopen("test","w"))==NULL)
    {
        printf("error: cannot open file!\n");
        exit(0);
    }
    fprintf(fp,"%s",str);
    fclose(fp);
    
    system("pause");
    return 0;
}
