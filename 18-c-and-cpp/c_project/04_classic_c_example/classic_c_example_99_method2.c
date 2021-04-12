/**
题目：有两个磁盘文件A和B,各存放一行字母，要求把这两个文件中的信息合并（按字母顺序排列），输出到一个新文件C中。

程序分析：你需要先创建 A.txt 与 B.txt。
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
        printf("打开或创建文件失败！");
        return -1;
    }

    str=(char *)malloc(NUM*sizeof(char));
    fgets(str,100,a);     //str末尾有换行和'\0'
     printf("str length %d \n",strlen(str));
    printf("%s \n",str);   //直接输出能正确输出一行字符串，且会换行
    int i=0;
    while(*(str+i)!='\n')
    {
        i++;
    }
    printf("i = %d \n",i);
    //此时*(str+i)='\n'
    fgets((str+i),100,b);
    
    printf("%s",str);   //直接输出能正确输出一行字符串，且会换行
    
    int length=(int)strlen(str)-1;   //减去末尾的换行符
    for(i=0;i<length-1;i++)
    {
    	int j;
        for(j=i+1;j<length;j++)
        {
            if(*(str+i)>*(str+j))  //升序排序
            {
                char temp=*(str+i);
                *(str+i)=*(str+j);
                *(str+j)=temp;
            }
        }
    }
    if(fprintf(c,"%s",str)>0)
        printf("写入文件成功！");
    else
        printf("写入文件失败！");
    free(str);
    fclose(a);
    fclose(b);
    fclose(c);

    return 0;

}
