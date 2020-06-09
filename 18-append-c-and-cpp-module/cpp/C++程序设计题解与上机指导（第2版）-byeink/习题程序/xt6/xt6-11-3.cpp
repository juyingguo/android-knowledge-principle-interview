#include <iostream>
#include <string>
using namespace std;
int main()
{void sort(string *);
 int i;
 string str[10],*p=str;
 cout<<"input 10 strings:"<<endl;
 for (i=0;i<10;i++)
   cin>>str[i];
 sort(p);
 cout<<"Now,the sequence is:"<<endl;
 for (i=0;i<10;i++)
   cout<<str[i]<<endl;
 return 0;
}

void sort(string *s)
{int i,j;
 string temp;
 for (i=0;i<9;i++)
   for (j=0;j<9-i;j++)
     if (s[j]>s[j+1])
      {temp=s[j];
       s[j]=s[+j+1];
       s[j+1]=temp;
      }
}
