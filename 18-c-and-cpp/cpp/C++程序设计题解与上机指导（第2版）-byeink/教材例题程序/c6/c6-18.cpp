#include <iostream>
using namespace std;
int main()
{void swap(int,int);
 int i=3;
 int j=5;
 swap(i,j);
 cout<<i<<" "<<j<<endl;
 return 0;
}

void swap(int a,int b)
{int temp;
 temp=a;
 a=b;
 b=temp;
}
