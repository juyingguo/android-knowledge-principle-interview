#include <iostream>
using namespace std;
int main()
 {int length(char *p);
  int len;
  char str[20];
  cout<<"input string:";
  cin>>str;
  len=length(str);
  cout<<"The length of string is "<<len<<endl;
  return 0;
}
int length(char *p)            //求字符串长度的函数
{int n;
 n=0;
 while (*p!='\0')
  {n++;
   p++;
  }
 return(n);
}

