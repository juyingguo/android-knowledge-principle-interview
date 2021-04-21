//#include <iostream>
//
//using namespace std;
#include "Singleton_lanhan.h"

//《懒汉模式》：因为这样的方式只有在我调用 CSingleton::GetInstance() 的时候才会返回一个实例化的对象，懒死了，我不要你你就不给我，是不是？
SingletonLH::SingletonLH()
{
    cout << "SingletonLH..." << endl;
}

SingletonLH::~SingletonLH()
{
    cout << "~ SingletonLH() call." << endl;
}

SingletonLH* SingletonLH::GetInstanceLH()
{
    static SingletonLH* _instancelh = new SingletonLH();    //对象在类的静态函数中定义，不用在外部声明

    return _instancelh;
}

int main()
{
    SingletonLH* sgnlh = SingletonLH::GetInstanceLH();
    SingletonLH* sgnlh1 = SingletonLH::GetInstanceLH();
    cout << "&sgnlh = " << sgnlh << '\t' << "&sgnlh1 = " << sgnlh1 << endl;         //两个地址一样，静态数据成员只能被初始化一次

    static SingletonLH * _instance_def = new SingletonLH();
    cout<<"&_instance_def = "<<_instance_def<<endl;
    getchar();
    return 0;
}
