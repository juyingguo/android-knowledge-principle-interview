/*
const_cast
*/
#include <iostream>

using namespace std;

int main() {
    const int constant = 21;
    const int* const_p  = &constant;//只有用指针或者引用，让变量指向同一个地址才是解决方案，可惜下边的代码在C++中也是编译不过的
    int* modifier = const_cast<int*>(const_p);
    *modifier = 7;
    cout << "constant: "<< constant <<endl;
    cout << "const_p: "<< *const_p <<endl;
    cout << "modifier: "<< *modifier <<endl;
}
