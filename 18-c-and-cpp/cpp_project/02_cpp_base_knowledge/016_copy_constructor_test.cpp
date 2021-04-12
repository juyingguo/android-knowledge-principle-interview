#include <iostream>
 
using namespace std;
 
class Line
{
   public:
      int getLength( void );
      Line( int len );             // �򵥵Ĺ��캯��
      Line( const Line &obj);      // �������캯��
      ~Line();                     // ��������
 
   private:
      int *ptr;
};
 
// ��Ա�������壬�������캯��
Line::Line(int len)
{
    cout << "���ù��캯��" << endl;
    // Ϊָ������ڴ�
    ptr = new int;
    *ptr = len;
}
 
Line::Line(const Line &obj)
{
    cout << "���ÿ������캯����Ϊָ�� ptr �����ڴ�" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // ����ֵ
}
 
Line::~Line(void)
{
    cout << "�ͷ��ڴ�" << endl;
    delete ptr;
}
int Line::getLength( void )
{
    return *ptr;
}
 
void display(Line obj)
{
   cout << "line ��С : " << obj.getLength() <<endl;
}
 
// �����������
int main( )
{
   Line line(10);
 
   display(line);
 
   return 0;
}
