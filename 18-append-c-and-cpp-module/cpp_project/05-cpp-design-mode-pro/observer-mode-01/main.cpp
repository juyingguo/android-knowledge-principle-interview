//main.cpp
#include "Subject.h"
#include "Observer.h"
#include <iostream>
using namespace std;

void test02()
{
    ConcreteSubject* sub = new ConcreteSubject();
    Observer* o1 = new ConcreteObserverA(sub);
    Observer* o2 = new ConcreteObserverB(sub);//�յĹ��캯����
    sub->SetState("hello");
    sub->Notify();
    sub->SetState("world"); // Ҳ �� �� ��Observer ����
    sub->Notify();
}
int main(int argc,char* argv[])
{
    ConcreteSubject* sub = new ConcreteSubject();
    Observer* o1 = new ConcreteObserverA(sub);
    Observer* o2 = new ConcreteObserverB(sub);
    sub->SetState("old");
    sub->Notify();
    sub->SetState("new"); // Ҳ �� �� ��Observer ����
    sub->Notify();

    ///////////
    test02();

    return 0;
}

