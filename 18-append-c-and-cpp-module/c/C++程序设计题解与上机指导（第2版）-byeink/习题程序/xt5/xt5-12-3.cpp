#include <iostream>
#include <string>
using namespace std;
int main()
 {int j;
  string ch="I will visit China next week.",tran;
  tran=ch;
  cout<<"cipher code:"<<ch<<endl;
  j=0;
  while (j<=ch.size())
  { if ((ch[j]>='A') && (ch[j]<='Z'))
      tran[j]=155-ch[j];
    else if ((ch[j]>='a') && (ch[j]<='z'))
	  tran[j]=219-ch[j];
    else
	  tran[j]=ch[j];
    j++;
  }
  cout<<"original text:";
  cout<<tran<<endl;
  return 0;
 }

	
	