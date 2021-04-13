#include <iostream>
using namespace std;
int main ()
{float s=0,t=1;
  int n;
  for (n=1;n<=20;n++)
  {
   t=t*n;      // 求n! 
   s=s+t;      // 将各项累加 
  }
  cout<<"1!+2!+...+20!="<<s<<endl;
  return 0;
  } 
 
