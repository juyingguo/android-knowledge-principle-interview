/*
const_cast
*/
#include <iostream>

using namespace std;

int main() {
    const int constant = 21;
    const int* const_p  = &constant;//ֻ����ָ��������ã��ñ���ָ��ͬһ����ַ���ǽ����������ϧ�±ߵĴ�����C++��Ҳ�Ǳ��벻����
    int* modifier = const_cast<int*>(const_p);
    *modifier = 7;
    cout << "constant: "<< constant <<endl;
    cout << "const_p: "<< *const_p <<endl;
    cout << "modifier: "<< *modifier <<endl;
}
