#include <iostream>
using namespace std;
int main ()
{int i,j,k,n;
 cout<<"narcissus numbers are:"<<endl;
     for (n=100;n<1000;n++)
      {i=n/100;
       j=n/10-i*10;
       k=n%10;
       if (n == i*i*i + j*j*j + k*k*k)
         cout<<n<<" ";
      }
    cout<<endl;
	return 0;
  }
