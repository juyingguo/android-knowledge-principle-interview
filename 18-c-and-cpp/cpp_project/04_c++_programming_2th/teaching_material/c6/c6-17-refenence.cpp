#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
 int a=10;
 int &b=a;
 a=a*a;
 cout<<a<<setw(4)<<b<<endl;
 b=b/5;
 cout<<b<<setw(6)<<a<<endl;
 return 0;
}
