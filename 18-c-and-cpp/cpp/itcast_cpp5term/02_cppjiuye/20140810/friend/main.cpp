#include <iostream>

using namespace std;

class demo0;

class demo
{
private:
    int i;//只能在类的内部访问
public:
    demo()//构造函数
    {
        cout << "demo" << this <<endl;
    }
    demo(const demo &it)//拷贝构造
    {
        this->i = it.i;//一旦自己实现了拷贝构造函数，类成员之间的赋值就需要自己完成，编译器不管了
        cout << "copy demo" << this << endl;
    }
    ~demo()//析构
    {
        cout << "~demo" << this << endl;
    }
    void set_i(int i)
    {
        this->i = i;
    }
    int get_i()
    {
        return i;
    }
    friend void test();//意思是声明一个该类的友元函数
    friend class demo1;//意思是声明一个该类的友元类
    friend class demo0;//demo 和demo0互为朋友
};

void test()//对于test来讲可以自由的访问demo当中的任意成员
{
//    demo d;
//    d.set_i(100);
//    cout<< "d.get_i()=" <<d.get_i()<<endl;

        demo d;
        d.i = 100;
        cout<< "test(),d.get_i()=" <<d.get_i()<<endl;
}

class demo0
{
private:
   int i;
public:
    demo0()
    {
        cout<< "demo0() enter." << endl;
        demo d;
        d.i = 500;
        cout<< "demo0(),d.get_i()=" <<d.get_i()<<endl;
    }
};


class demo1
{
public:
    demo1()
    {
        cout<< "demo1() enter." << endl;
        demo d;
        d.i = 600;
        cout<< "demo1(),d.get_i()=" <<d.get_i()<<endl;
    }
    friend class demo2;
};
//我的朋友的朋友，不会是我的朋友
class demo2
{
public:
    demo2()
    {
        demo d;
//        d.i = 100;
    }
};



int main()
{
    test();
    demo1 sdemo1;
    cout << "Hello World!" << endl;
    return 0;
}

