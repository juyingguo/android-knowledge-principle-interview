#include <iostream>
#include <string>
 
using namespace std;
 
int main ()
{
   string str1 = "Hello";
   string str2 = "World";
   string str3;
   int  len ;
 
   // ���� str1 �� str3
   str3 = str1;
   cout << "str3 : " << str3 << endl;
 
   // ���� str1 �� str2
   str3 = str1 + str2;
   cout << "str1 + str2 : " << str3 << endl;
 
   // ���Ӻ�str3 ���ܳ���
   len = str3.size();
   cout << "str3.size() :  " << len << endl;
 
   return 0;
}
