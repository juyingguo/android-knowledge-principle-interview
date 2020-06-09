#include <iostream>
#include <string>
using namespace std;
int main()
 {int j;
  string ch="I will visit China next week.";
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

	
	