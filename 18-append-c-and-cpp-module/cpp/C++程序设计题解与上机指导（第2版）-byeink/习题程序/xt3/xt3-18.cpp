#include <iostream>
using namespace std;
int main ()
{float s=0,t=1;
  int n;
  for (n=1;n<=20;n++)
  {
   t=t*n;      // ��n! 
   s=s+t;      // �������ۼ� 
  }
  cout<<"1!+2!+...+20!="<<s<<endl;
  return 0;
  } 
 
