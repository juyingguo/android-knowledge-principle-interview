#include <iostream>
using namespace std;
int main()
{void sort(char *[]);
 int i;
 char *p[10],str[10][20];
 for (i=0;i<10;i++)
   p[i]=str[i];        //将第i个字符串的首地址赋予指针数组p的第i个元素
 cout<<"input 10 strings:"<<endl;
 for (i=0;i<10;i++)
   cin>>p[i];
 sort(p);
 cout<<"Now,the sequence is:"<<endl;
 for (i=0;i<10;i++)
   cout<<p[i]<<endl;
 return 0;
}

void sort(char *s[])
{int i,j;
 char *temp;
 for (i=0;i<9;i++)
   for (j=0;j<9-i;j++)
     if (strcmp(*(s+j),*(s+j+1))>0)
       {temp=*(s+j);
        *(s+j)=*(s+j+1);
        *(s+j+1)=temp;
       }
}
