//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015�� ����̳�. All rights reserved.
//
/**
��Ŀ���Ӽ�������һЩ�ַ�������������͵�������ȥ��ֱ������һ��#Ϊֹ��
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE*fp=NULL;
    char filename[25];
    char ch;
    printf("������Ҫ���浽���ļ������ƣ�\n");
    gets(filename);
    if((fp=fopen(filename,"w"))==NULL)
    {
        printf("error: cannot open file!\n");
        exit(0);
    }
    printf("���������������Ҫ�����һЩ�ַ�����#������\n");
    ch = getchar();
    /*while((ch=getchar())!='#' ){//������#�����������Իس�����'\r' 
        fputc(ch,fp);
    }*/
    while(ch!='#' && ch!= '\n' /*&& ch != '\r'*/){//������#�����������Իس����н���'\n' 
        fputc(ch,fp);
        ch = getchar();
    }
    fclose(fp);
    system("pause");
    return 0;
}
