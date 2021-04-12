/*
static_cast 类型转换
*/
#include <iostream>

using namespace std;

int main() {
    int* pi = NULL;
    //char c = int(pi); //C++类型转换
    //char c = (int)pi; //C类型转换
    void* pc = pi;
    pi = static_cast<int *>(pc);
    char c = static_cast<int>(pi); //会出现报错，因为int* 无法转换为int类型

}
