/**
��Ŀ�������������ļ�A��B,�����һ����ĸ��Ҫ����������ļ��е���Ϣ�ϲ�������ĸ˳�����У��������һ�����ļ�C�С�

�������������Ҫ�ȴ��� A.txt �� B.txt��
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 10

int main()
{
    FILE *a=NULL,*b=NULL,*c=NULL;
    char *str=NULL;

    a=(FILE *)fopen("./A.txt","r");
    b=(FILE *)fopen("./B.txt","r");
    c=(FILE *)fopen("./C.txt","w");
    if(a==NULL || b==NULL || c==NULL)
    {
        printf("�򿪻򴴽��ļ�ʧ�ܣ�");
        return -1;
    }

    str=(char *)malloc(NUM*sizeof(char));
    fgets(str,100,a);     //strĩβ�л��к�'\0'
     printf("str length %d \n",strlen(str));
    printf("%s \n",str);   //ֱ���������ȷ���һ���ַ������һỻ��
    int i=0;
    while(*(str+i)!='\n')
    {
        i++;
    }
    printf("i = %d \n",i);
    //��ʱ*(str+i)='\n'
    fgets((str+i),100,b);
    
    printf("%s",str);   //ֱ���������ȷ���һ���ַ������һỻ��
    
    int length=(int)strlen(str)-1;   //��ȥĩβ�Ļ��з�
    for(i=0;i<length-1;i++)
    {
    	int j;
        for(j=i+1;j<length;j++)
        {
            if(*(str+i)>*(str+j))  //��������
            {
                char temp=*(str+i);
                *(str+i)=*(str+j);
                *(str+j)=temp;
            }
        }
    }
    if(fprintf(c,"%s",str)>0)
        printf("д���ļ��ɹ���");
    else
        printf("д���ļ�ʧ�ܣ�");
    free(str);
    fclose(a);
    fclose(b);
    fclose(c);

    return 0;

}
