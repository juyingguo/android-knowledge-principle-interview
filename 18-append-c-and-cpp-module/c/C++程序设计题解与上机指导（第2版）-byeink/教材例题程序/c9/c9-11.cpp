#include <iostream>
using namespace std;
class Student
 {public:
   Student(int,int,int);
   void total();
   static float average();
  private:
   int num;
   int age;
   float score;
   static float sum;
   static int count;
 };

 Student::Student(int m,int a,int s)
 {num=m;
  age=a;
  score=s;
 }
 
void Student::total()
   {
    sum+=score;
    count++;
   }
   
float  Student::average()
 { return(sum/count);
 }

float Student::sum=0;
int Student::count=0;

int main()
 {
   Student stud[3]={
     Student(1001,18,70),
     Student(1002,19,79),
     Student(1005,20,98)
    };
   int n;
   cout<<"please input the number of students:";
   cin>>n;
   for(int i=0;i<n;i++)
     stud[i].total();
   cout<<"The average score of "<<n<<" students is "<<stud[0].average()<<endl;
   return 0;
 }
 
 
