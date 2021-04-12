#include <iostream>

using namespace std;

class demo
{
public:
    demo()
    {
        cout << "demo" << endl;
    }
    demo(int i)
    {
        cout << "demo int" << i << endl;
    }

    ~demo()
    {
        cout << "~demo" << endl;
    }
};

int main()
{
    demo d[3] = {demo(1), demo(2),demo(3)};//定义对象数组，同时调用带参数的构造函数.
    cout << "Hello World!" << endl;
    return 0;
}

