//xt8-4-2.cpp(��student.cpp)
#include "xt8-4.h"                      //�ڴ��ļ��н��к����Ķ���
#include <iostream>  
using namespace std;                   //��Ҫ©д����
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

