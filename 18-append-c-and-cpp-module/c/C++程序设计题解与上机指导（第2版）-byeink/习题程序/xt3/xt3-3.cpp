#include <iostream>
using namespace std;
int main ()
{float c,f;
 cout<<"请输入一个华氏温度:";
 cin>>f;
 c=(5.0/9.0)*(f-32);         //注意5和9要用实型表示,否则5/9值为0
 cout<<"摄氏温度为:"<<c<<endl;
 return 0;
};


