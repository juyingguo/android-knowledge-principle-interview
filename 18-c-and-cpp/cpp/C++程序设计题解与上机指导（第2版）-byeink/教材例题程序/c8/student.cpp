//student.cpp                            这是源文件，在此文件中进行函数的定义
#include <iostream>
#include "student.h"                    //不要漏写此行
void Student::display( )                 //在类外定义display类函数
{cout<<"num:"<<num<<endl;
 cout<<"name:"<<name<<endl;
 cout<<"sex:"<<sex<<endl;
}
