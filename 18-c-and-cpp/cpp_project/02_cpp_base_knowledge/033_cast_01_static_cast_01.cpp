/*
static_cast ����ת��
*/
#include <iostream>

using namespace std;

int main() {
    int a = 100;
    int* pi = &a;
    //char c = int(pi); //C++����ת��
    //char c = (int)pi; //C����ת��
    void* pc = pi;
    pi = static_cast<int *>(pc);
    cout<<"pi = "<<pi<<"\n*pi="<<*pi<<endl;
    int *c = static_cast<int*>(pi); //����ֱ�����Ϊint* �޷�ת��Ϊint����

}
