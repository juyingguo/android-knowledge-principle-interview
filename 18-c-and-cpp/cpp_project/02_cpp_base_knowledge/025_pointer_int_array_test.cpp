#include <iostream>
 
using namespace std;
 
int main ()
{
   int  var1;
   int var2[10];
 
 	int *p = var2;
	
   cout << "var1 �����ĵ�ַ�� ";
   cout << &var1 << endl;
 
   cout << "var2 �����ĵ�ַ�� ";
   cout << &var2 << endl;
 
   cout << "p�ĵ�ַ�� ";
   cout << p << endl;
   return 0;
}
