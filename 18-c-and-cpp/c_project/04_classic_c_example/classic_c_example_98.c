//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015�� ����̳�. All rights reserved.
//
/**
��Ŀ���Ӽ�������һ���ַ�������Сд��ĸȫ��ת���ɴ�д��ĸ��Ȼ�������һ�������ļ�"test"�б��档 ������ַ����ԣ�������
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int main()
{
    FILE*fp=NULL;
    char str[50];
    int i,len;
    printf("����һ���ַ�����\n");
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
