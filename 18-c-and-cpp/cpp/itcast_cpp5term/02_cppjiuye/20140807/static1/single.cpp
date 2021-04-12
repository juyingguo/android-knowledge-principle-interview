#include "single.h"
#include <iostream>

single *single::p = NULL;
using namespace std;
single::single()
{
    cout << "single()" << endl;
}

single *single::makesignle()
{
    if (p == NULL)
        p = new single;//如果p为空，就实例化对象，否则
    return p;
}

void single::releasesingle()
{
    delete p;
    p = NULL;
}
