/*
const_cast
*/
#include <iostream>

using namespace std;

int main() {
    //volatile表示易变的，可以变化的
    const /*volatile*/ int ci = 100; //volatile 表示数字是易变.加上volatile，才可以使用const_cast指针转换后修改const变量的值。
//    int ci = 100; //表示数字是易变
    int* pi = const_cast<int *>(&ci); //进行地址的赋值操作
    *pi = 200; //对地址进行赋值
    cout << *pi << endl;
    cout << ci << endl;
    cout << (void *)&ci << endl;
    cout << pi << endl;
}
