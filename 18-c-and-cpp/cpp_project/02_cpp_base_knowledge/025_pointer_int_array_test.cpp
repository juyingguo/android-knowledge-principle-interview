#include <iostream>
 
using namespace std;
 
int main ()
{
   int  var1;
   int var2[10];
 
 	int *p = var2;
	
   cout << "var1 变量的地址： ";
   cout << &var1 << endl;
 
   cout << "var2 变量的地址： ";
   cout << &var2 << endl;
 
   cout << "p的地址： ";
   cout << p << endl;
   return 0;
}
