/**
��������������������������������
��Ȩ����������ΪCSDN������ucasliyang����ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/ucasliyang/article/details/52691619

*/

#include<iostream>
#include<string>
 
struct Person
{
  Person(std::string name);
  std::string greet(std::string other_name);
	//std::string m_name;//default  public
	public : std::string m_name;//default  public
};
 
Person::Person(std::string name)
{
    m_name = name;
}
 
std::string Person::greet(std::string other_name)
{
    return "Hi " + other_name + ", my name is " + m_name;
}
 
int main()
{
    Person m_person("JANE");
    std::string str = m_person.greet("JOE");
    std::cout<<str<<std::endl;
    std::cout<<m_person.m_name<<std::endl;
}

