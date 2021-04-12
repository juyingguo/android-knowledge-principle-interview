//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015年 菜鸟教程. All rights reserved.
//
/**
题目：从键盘输入一些字符，逐个把它们送到磁盘上去，直到输入一个#为止。
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE*fp=NULL;
    char filename[25];
    char ch;
    printf("输入你要保存到的文件的名称：\n");
    gets(filename);
    if((fp=fopen(filename,"w"))==NULL)
    {
        printf("error: cannot open file!\n");
        exit(0);
    }
    printf("现在你可以输入你要保存的一些字符，以#结束：\n");
    ch = getchar();
    /*while((ch=getchar())!='#' ){//或者以#结束，或者以回车结束'\r' 
        fputc(ch,fp);
    }*/
    while(ch!='#' && ch!= '\n' /*&& ch != '\r'*/){//或者以#结束，或者以回车换行结束'\n' 
        fputc(ch,fp);
        ch = getchar();
    }
    fclose(fp);
    system("pause");
    return 0;
}
