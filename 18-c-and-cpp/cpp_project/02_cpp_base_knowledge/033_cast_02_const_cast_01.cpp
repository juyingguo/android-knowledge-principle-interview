/*
const_cast
*/
#include <iostream>

using namespace std;

int main() {
    //volatile��ʾ�ױ�ģ����Ա仯��
    const /*volatile*/ int ci = 100; //volatile ��ʾ�������ױ�.����volatile���ſ���ʹ��const_castָ��ת�����޸�const������ֵ��
//    int ci = 100; //��ʾ�������ױ�
    int* pi = const_cast<int *>(&ci); //���е�ַ�ĸ�ֵ����
    *pi = 200; //�Ե�ַ���и�ֵ
    cout << *pi << endl;
    cout << ci << endl;
    cout << (void *)&ci << endl;
    cout << pi << endl;
}
