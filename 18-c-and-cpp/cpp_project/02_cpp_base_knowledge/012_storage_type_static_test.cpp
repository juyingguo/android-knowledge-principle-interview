#include <iostream>
 
// �������� 
void func(void);
 
static int count = 3; /* ȫ�ֱ��� */
 
int main()
{
    while(count--)
    {
       func();
    }
    return 0;
}
// ��������
void func( void )
{
    static int i = 5; // �ֲ���̬����
    i++;
    std::cout << "���� i Ϊ " << i ;
    std::cout << " , ���� count Ϊ " << count << std::endl;
}
