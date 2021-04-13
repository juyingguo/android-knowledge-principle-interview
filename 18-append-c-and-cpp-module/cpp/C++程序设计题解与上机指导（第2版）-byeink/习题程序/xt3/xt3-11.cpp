#include <iostream>
using namespace std;
int main ()
 {float score;
  char grade;
  cout<<"please enter score of student:"; 
  cin>>score;
  while (score>100||score<0)
    {cout<<"data error,enter data again.";
      cin>>score;
     }
 switch(int(score/10))
       {case 10:
        case 9: grade='A';break;
        case 8: grade='B';break;
        case 7: grade='C';break;
        case 6: grade='D';break;
        default:grade='E';        
       }
   cout<<"score is "<<score<<", grade is "<<grade<<endl;
   return 0;
}