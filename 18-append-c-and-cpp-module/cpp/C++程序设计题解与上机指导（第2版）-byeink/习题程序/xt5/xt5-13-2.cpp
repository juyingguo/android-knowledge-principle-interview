#include <iostream>
using namespace std;
int main()
{char s1[80],s2[40];
  cout<<"input string1:";
  cin>>s1;
  cout<<"input string2:";
  cin>>s2;
  strcat(s1,s2);
  cout<<"The new string is:"<<s1<<endl;
  return 0;
}
 
 
