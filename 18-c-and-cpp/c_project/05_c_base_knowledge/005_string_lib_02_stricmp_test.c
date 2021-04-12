/**
C语言stricmp()函数：比较字符串（不区分大小写）.
http://cdn-mozhiyan.biancheng.net/cpp/html/2713.html

【返回值】若参数s1 和s2 字符串相同则返回0。s1 若大于s2 则返回大于0 的值。s1 若小于s2 则返回小于0 的值。

注意：stricmp()是Windows下特有的，linux下具有相同功能的函数是strcasecmp()，包含在头文件strings.h下。

另外一个不区分大小写比较字符串的函数是strcmpi()，strcmpi()是stricmp()的宏定义，实际未提供此函数。
 
*/
#include<stdio.h>
#include<string.h>
int main(void)
{
    /*定义两个字符串*/
    char* s1 = "http://see.xidian.edu.cn/cpp/nihao";
    char* s2 = "http://see.xidian.edu.cn/cpp/world/";
    /*比较字符串（不分大小写）*/
    int result = stricmp(s1,s2);  // 也可以改成strcmpi()
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
    getchar();/*等待用户输入个字符，然后退出*/
    return 2;
}
