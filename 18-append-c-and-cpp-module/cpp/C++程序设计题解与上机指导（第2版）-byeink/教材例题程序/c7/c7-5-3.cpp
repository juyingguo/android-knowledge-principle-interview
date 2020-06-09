#include <iostream>
#include <string>
using namespace std;
struct Student
{int num;
 string name;
 float score[3];
}stu={12345,"Li Fung",67.5,89,78.5};

int main()
{void print(Student &);
 print(stu);
 return 0;
}

void print(Student &stud)
{cout<<stud.num<<" "<<stud.name<<" "<<stud.score[0]<<" "<<stud.score[1]<<" "<<stud.score[2]<<endl;
}
