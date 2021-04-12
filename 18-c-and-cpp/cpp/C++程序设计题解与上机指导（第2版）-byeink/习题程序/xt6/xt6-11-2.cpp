#include <iostream>
using namespace std;
int main()
{void sort(char (*p)[6]);
 int i;
 char str[10][6];
 char (*p)[6];
 cout<<"input 10 strings:"<<endl;
 for (i=0;i<10;i++)
   cin>>str[i];
 p=str;
 sort(p);
 cout<<"Now,the sequence is:"<<endl;
 for (i=0;i<10;i++)
   cout<<str[i]<<endl;
 return 0;
}

void sort(char (*s)[6])
{int i,j;
 char temp[6],*t=temp;
 for (i=0;i<9;i++)
   for (j=0;j<9-i;j++)
     if (strcmp(s[j],s[j+1])>0)
      {strcpy(t,s[j]);
       strcpy(s[j],s[+j+1]);
       strcpy(s[j+1],t);
      }
}
