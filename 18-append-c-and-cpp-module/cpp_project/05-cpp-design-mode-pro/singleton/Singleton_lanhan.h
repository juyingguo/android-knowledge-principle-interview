#include <stdlib.h>
#include <iostream>

using namespace std;

class SingletonLH
{
public:
    SingletonLH();
    ~SingletonLH();
    static SingletonLH* GetInstanceLH();

protected:

private:
};

