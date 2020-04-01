#include <iostream>
using namespace std;
int main()
{void sort(char s[][6]);
 int i;
 char str[10][6];
 cout<<"input 10 strings:"<<endl;
 for (i=0;i<10;i++)
   cin>>str[i];
 sort(str);
 cout<<"Now,the sequence is:"<<endl;
 for (i=0;i<10;i++)
   cout<<str[i]<<endl;
 return 0;
}

void sort(char s[][6])
{int i,j;
 char *p,temp[10];
 p=temp;
 for (i=0;i<9;i++)
   for (j=0;j<9-i;j++)
     if (strcmp(s[j],s[j+1])>0)
      {strcpy(p,s[j]);
       strcpy(s[j],s[+j+1]);
       strcpy(s[j+1],p);
      }
}
