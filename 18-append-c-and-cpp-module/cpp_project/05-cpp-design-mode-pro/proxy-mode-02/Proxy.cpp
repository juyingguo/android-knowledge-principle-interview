//Proxy.cpp
#include "Proxy.h"
#include <iostream>
using namespace std;
Subject::Subject()
{
    cout<<"Subject()"<<endl;
}

Subject::~Subject()
{
    cout<<"~Subject()"<<endl;
}
ConcreteSubject::ConcreteSubject()
{
    cout<<"ConcreteSubject()"<<endl;
}
ConcreteSubject::~ConcreteSubject()
{
    cout<<"~ConcreteSubjec()"<<endl;
}
void ConcreteSubject::Request()
{
    cout<<"ConcreteSubject......request...."<<endl;
}
Proxy::Proxy()
{
}
Proxy::Proxy(Subject* sub)
{
    _sub = sub;
}
Proxy::~Proxy()
{
    delete _sub;
}
void Proxy::Request()
{
    cout<<"Proxy request...."<<endl;
    _sub->Request();
}
