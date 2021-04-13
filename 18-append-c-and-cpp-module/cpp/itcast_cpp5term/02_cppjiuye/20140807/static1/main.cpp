#include <iostream>
#include "single.h"

using namespace std;

//实例化单例的例子
int main()
{
    single *p = single::makesignle();

    single *p1 = single::makesignle();

    single::releasesingle();
    cout << "Hello World!" << endl;
    return 0;
}

