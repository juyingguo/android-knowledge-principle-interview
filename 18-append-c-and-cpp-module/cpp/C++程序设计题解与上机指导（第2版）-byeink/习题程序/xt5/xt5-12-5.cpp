#include <iostream>
#include <string>
using namespace std;
int main()
 {int j;
  string ch="                              ";
  char *p=&ch[0];            //�����ַ�ָ�벢ʹָ֮��ch�����ַ�
  cout<<"input cipher code:";
  gets(p);                  //�Ӽ��̶���һ���ַ�
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

	
	