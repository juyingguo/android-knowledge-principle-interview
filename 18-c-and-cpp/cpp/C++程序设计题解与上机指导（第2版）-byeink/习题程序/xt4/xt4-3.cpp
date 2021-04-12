#include <iostream>
using namespace std;
int main()
 {int prime(int);                /* 函数原型声明 */
  int n;
  cout<<"input an integer:";
  cin>>n;
  if (prime(n))
    cout<<n<<" is a prime."<<endl;
  else
    cout<<n<<" is not a prime."<<endl;
  return 0;
 }

 int prime(int n)
  {int flag=1,i;
   for (i=2;i<n/2 && flag==1;i++)
     if (n%i==0)
       flag=0;
   return(flag);
  }
 


