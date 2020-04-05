#include <iostream>
using namespace std;
int main()
{int strcmp(char *p1,char *p2);
 int m;
 char str1[20],str2[20],*p1,*p2;
 cout<<"input two strings:"<<endl;
 cin>>str1;
 cin>>str2;
 p1=&str1[0];
 p2=&str2[0];
 m=strcmp(p1,p2);
 cout<<"result:"<<m<<endl;
 return 0;
}

int strcmp(char *p1,char *p2)         //自已定义字符串比较函数 
{int i;
 i=0;
 while(*(p1+i)==*(p2+i))
   if (*(p1+i++)=='\0') return(0);     //全部字符相同时返回结果0 
 return(*(p1+i)-*(p2+i));     //不相同时返回结果为第一对不相同字符的ASCII码的差值 
} 
