#include <iostream>
#include <string>
using namespace std;
int main()
 {int j;
  string ch="                              ";
  char *p=&ch[0];            //定义字符指针并使之指向ch的首字符
  cout<<"input cipher code:";
  gets(p);                  //从键盘读入一行字符
  cout<<"cipher code:"<<ch<<endl;
  j=0;
  while (j<=ch.size())
  { if ((ch[j]>='A') && (ch[j]<='Z'))
      ch[j]=155-ch[j];
    else if ((ch[j]>='a') && (ch[j]<='z'))
	  ch[j]=219-ch[j];
    j++;
  }
  cout<<"original text:";
  cout<<ch<<endl;
  return 0;
 }

	
	