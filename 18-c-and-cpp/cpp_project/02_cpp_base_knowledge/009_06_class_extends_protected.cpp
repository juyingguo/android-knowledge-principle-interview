/**
only verify class extends . want to run suncess,please modiy code .
*/


#include<iostream>
#include<assert.h>
using namespace std;
class A{
public:
  int a;
  A(){
    a1 = 1;
    a2 = 2;
    a3 = 3;
    a = 4;
  }
  void fun(){
    cout << a << endl;    //��ȷ
    cout << a1 << endl;   //��ȷ
    cout << a2 << endl;   //��ȷ
    cout << a3 << endl;   //��ȷ
  }
public:
  int a1;
protected:
  int a2;
private:
  int a3;
};
class B : protected A{
public:
  int a;
  B(int i){
    A();
    a = i;
  }
  void fun(){
    cout << a << endl;       //��ȷ��public��Ա��
    cout << a1 << endl;       //��ȷ�������public��Ա�����������б����protected�����Ա���������ʡ�
    cout << a2 << endl;       //��ȷ�������protected��Ա�����������л���protected�����Ա���������ʡ�
    cout << a3 << endl;       //���󣬻����private��Ա���ܱ���������ʡ�
  }
};
int main(){
  B b(10);
  cout << b.a << endl;       //��ȷ��public��Ա
  cout << b.a1 << endl;      //����protected��Ա������������ʡ�
  cout << b.a2 << endl;      //����protected��Ա������������ʡ�
  cout << b.a3 << endl;      //����private��Ա������������ʡ�
  system("pause");
  return 0;
}
