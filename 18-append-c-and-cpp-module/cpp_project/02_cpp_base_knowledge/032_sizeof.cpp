/*
static_cast ����ת��
*/
#include <iostream>

using namespace std;

int main() {
    int* pi = NULL;
    //char c = int(pi); //C++����ת��
    //char c = (int)pi; //C����ת��
    void* pc = pi;
    pi = static_cast<int *>(pc);
    char c = static_cast<int>(pi); //����ֱ�����Ϊint* �޷�ת��Ϊint����

}
