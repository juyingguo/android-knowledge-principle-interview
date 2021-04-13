#include <iostream>
using namespace std;
int main()
 {int j,n;
  char ch[80];
  cout<<"input cipher code:";
  gets(ch);
  cout<<"cipher code:"<<ch<<endl;
  j=0;
  while (ch[j]!='\0')
  { if ((ch[j]>='A') && (ch[j]<='Z'))
      ch[j]=155-ch[j];
    else if ((ch[j]>='a') && (ch[j]<='z'))
      ch[j]=219-ch[j];
    else
      ch[j]=ch[j];
    j++;
  }
  n=j;
  cout<<"original text:";
  for (j=0;j<n;j++)
    putchar(ch[j]);
  cout<<endl;
  return 0;
 }

	
	