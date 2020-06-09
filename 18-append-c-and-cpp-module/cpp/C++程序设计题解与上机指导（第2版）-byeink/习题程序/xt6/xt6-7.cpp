#include <iostream>
using namespace std;
int main()
 {void copystr(char *,char *,int);
  int m;
  char str1[20],str2[20];
  cout<<"input string:";
  gets(str1);
  cout<<"which character do you want begin to copy?";
  cin>>m;
  if (strlen(str1)<m)
    cout<<"input error!"<<endl;
  else
   {copystr(str1,str2,m);
    cout<<"result:"<<str2<<endl;
   }
  return 0;
}

void copystr(char *p1,char *p2,int m)      //字符串部分复制函数*/
{int n;
 n=0;
 while (n<m-1)
  {n++;
   p1++;
  }
 while (*p1!='\0')
   {*p2=*p1;
    p1++;
    p2++;
   }
 *p2='\0';
}

	
	