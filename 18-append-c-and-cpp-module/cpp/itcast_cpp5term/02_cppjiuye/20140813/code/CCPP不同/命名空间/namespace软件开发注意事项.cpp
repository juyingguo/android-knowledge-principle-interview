#include <iostream>

namespace runmove
{
	int  y(5);
	int(*padd)(int, int);//����ָ��ӿ�
//private: �����ռ���͸����
	int  y1(5);
	class myclass
	{
	public://��Ĭ����˽�У�ʵ�ַ�װ
		int a;
	};
}

int add(int a, int b)
{

	return a + b;
}
int addp(int a, int b)
{
	std::cout << a << b;
	return a + b;
}
struct MyStruct
{
	int b;//�ṹ��Ĭ����͸����
private:
	int a;//��˽��
};

void main1123()
{
	//namespace�������ݣ��������࣬�����ǹ���
	MyStruct struct1;//�ṹ���ڲ�Ĭ�Ϲ���
	struct1.b;


}