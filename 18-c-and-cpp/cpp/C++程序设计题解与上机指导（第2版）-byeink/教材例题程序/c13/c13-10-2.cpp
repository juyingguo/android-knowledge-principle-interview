#include <iostream>
using namespace std;
int main()
{char ch[20];
 cin.get(ch,20,'/');
 cout<<"The first part is:"<<ch<<endl;
 cin.ignore();
 cin.get(ch,20,'/');
 cout<<"The second part is:"<<ch<<endl;
 return 0;
}

