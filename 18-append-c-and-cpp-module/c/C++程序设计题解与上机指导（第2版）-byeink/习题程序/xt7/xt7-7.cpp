#include <iostream>
using namespace std;
#define NULL 0     
struct student
{long num;
 float score;
 student *next;
};    
int n;                    
void print(student *head)
 {student *p;
  cout<<"Now£¬These "<<n<<" records are£º"<<endl;
  p=head;
  if(head!=NULL)
  do
    {cout<<p->num<<"  "<<p->score<<endl;
     p=p->next;
	}while(p!=NULL);
}
