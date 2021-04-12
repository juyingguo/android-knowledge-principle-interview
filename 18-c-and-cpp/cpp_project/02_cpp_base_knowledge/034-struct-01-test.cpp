/*
struct
*/
#include <iostream>
using namespace std;
struct MyTest;
struct Test{
    int a;
};
int main() {
    Test t;
    t.a = 10;
    cout<<"Test:"<<t.a<<endl;
    cout<<"main"<<endl;
    getchar();
    return 0;
}
