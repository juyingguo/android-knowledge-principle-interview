#include<iostream>
#include<stdlib.h>
namespace mydata
{
	int a(6);
}
namespace yourdata
{
	int a(10);
}
using namespace mydata;//using�����������ռ�ĺ��棬������
using namespace yourdata;
//using�����������������ֲ���ȷ���󣬼��������ռ����η�
void go()
{

	//�����ռ�����ڿ�������ݣ��������Ƕ��忪ʼ����������
	//std::cout << mydata::a << std::endl;

}


//using namespace mydata;//������Ϊ�Ӵ��뿪ʼ������
void main02()
{
	//std::cout << mydata::a << std::endl;
	std::cout <<yourdata::a << std::endl;



	system("pause");
}