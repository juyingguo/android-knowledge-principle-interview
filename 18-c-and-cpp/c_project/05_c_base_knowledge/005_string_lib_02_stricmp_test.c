/**
C����stricmp()�������Ƚ��ַ����������ִ�Сд��.
http://cdn-mozhiyan.biancheng.net/cpp/html/2713.html

������ֵ��������s1 ��s2 �ַ�����ͬ�򷵻�0��s1 ������s2 �򷵻ش���0 ��ֵ��s1 ��С��s2 �򷵻�С��0 ��ֵ��

ע�⣺stricmp()��Windows�����еģ�linux�¾�����ͬ���ܵĺ�����strcasecmp()��������ͷ�ļ�strings.h�¡�

����һ�������ִ�Сд�Ƚ��ַ����ĺ�����strcmpi()��strcmpi()��stricmp()�ĺ궨�壬ʵ��δ�ṩ�˺�����
 
*/
#include<stdio.h>
#include<string.h>
int main(void)
{
    /*���������ַ���*/
    char* s1 = "http://see.xidian.edu.cn/cpp/nihao";
    char* s2 = "http://see.xidian.edu.cn/cpp/world/";
    /*�Ƚ��ַ��������ִ�Сд��*/
    int result = stricmp(s1,s2);  // Ҳ���Ըĳ�strcmpi()
    if(result>0)
    {
        printf("Result: s1 > s2");
    }
    else if(result<0)
    {
        printf("Result: s1 < s2");
    }
    else if(result == 0)
    {
        printf("Result: s1 = s2");
    }   
    getchar();/*�ȴ��û�������ַ���Ȼ���˳�*/
    return 2;
}
