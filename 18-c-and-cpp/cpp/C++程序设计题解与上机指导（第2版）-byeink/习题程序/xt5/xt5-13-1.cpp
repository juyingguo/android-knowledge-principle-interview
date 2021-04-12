#include <iostream>
#include <string>
using namespace std;
int main()
{char s1[80],s2[40];
  int i=0,j=0;
  cout<<"input string1:";
  cin>>s1;
  cout<<"input string2:";
  cin>>s2;
  while (s1[i]!='\0')
    i++;
  while(s2[j]!='\0')
    s1[i++]=s2[j++];
  s1[i]='\0';
  cout<<"The new string is:"<<s1<<endl;
  return 0;
}
 
 
