/**
————————————————
版权声明：本文为CSDN博主「ucasliyang」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/ucasliyang/article/details/52691619

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

