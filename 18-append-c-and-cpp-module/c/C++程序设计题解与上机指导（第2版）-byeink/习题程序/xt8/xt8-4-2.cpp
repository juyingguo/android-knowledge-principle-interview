//xt8-4-2.cpp(即student.cpp)
#include "xt8-4.h"                      //在此文件中进行函数的定义
#include <iostream>  
using namespace std;                   //不要漏写此行
void Student::display( )              
{ cout<<"num:"<<num<<endl;
  cout<<"name:"<<name<<endl;
  cout<<"sex:"<<sex<<endl;
}

void Student::set_value()
{ cin>>num;
  cin>>name;
  cin>>sex;
}

