#include <iostream>
using namespace std;
#define NULL 0     
struct student
{long num;
 float score;
 student *next;
};    
int n; 

int main()
{ student *creat(void);
  student *del(student *,long);  
  student *insert(student *,student *);
  void print(student *);
  student *head,*stu;
  long del_num;
  cout<<"input records:"<<endl;
  head=creat();                        //����ͷָ��
  print(head);                          //���ȫ�����
  cout<<endl<<"input the deleted number:";
  cin>>del_num;                        //����Ҫɾ����ѧ��
  while(del_num!=0)
  {head=del(head,del_num);              //ɾ���������ͷ��ַ
   print(head);                         //���ȫ�����
   cout<<"input the deleted number:";
   cin>>del_num; 
  }
  cout<<endl<<"input the inserted record:";  //����Ҫ����Ľ��
  stu=new student;                      //����һ���½��
  cin>>stu->num>>stu->score;
  while(stu->num!=0)
  {head=insert(head,stu);              //���ص�ַ
   print(head);                         //���ȫ�����
   cout<<endl<<"input the inserted record:";  //����Ҫ����Ľ��
   stu=new student;
   cin>>stu->num>>stu->score;
  }
  return 0;
}

student *creat(void)       //��������ĺ���
{student *head;
 student *p1,*p2;
 n=0;
 p1=p2=new student;       //����һ���µ�Ԫ����ʹp1,p2ָ����
 cin>>p1->num>>p1->score;
 head=NULL;
 while(p1->num!=0)
{n=n+1;
 if(n==1) head=p1;
 else p2->next=p1;
 p2=p1;
 p1=new student;
 cin>>p1->num>>p1->score;
}
p2->next=NULL;
return(head);
}    

student *del(student *head,long num)   //ɾ�����ĺ���
{student *p1,*p2;
 if (head==NULL)                    //�ǿձ�
 {cout<<"list null!"<<endl; return(head);}
 p1=head;                          //ʹp1ָ���һ�����
 while(num!=p1->num && p1->next!=NULL) //p1ָ��Ĳ�����Ҫ�ҵĽ���Һ��滹�н��
 {p2=p1; p1=p1->next;}                 //p1����һ�����
 if(num==p1->num)                        //�ҵ���
 {if(p1==head) head=p1->next;   //��p1ָ������׽�㣬�ѵڶ�������ַ����head
  else p2->next=p1->next;    //������һ����ַ����ǰһ����ַ
  cout<<"delete:"<<num<<endl;
  n=n-1;
 }
 else cout<<"cannot find "<<num;     //�Ҳ����ý��
 return(head);
}
    
student *insert(student *head,student *stud)  //������ĺ���
{student *p0,*p1,*p2;
 p1=head;                          //ʹp1ָ���һ�����
 p0=stud;                          //ָ��Ҫ����Ľ��
 if(head==NULL)                    //ԭ���������ǿձ�
 {head=p0;p0->next=NULL;}          //ʹp0ָ��Ľ����Ϊͷ���
 else
 {while((p0->num>p1->num) && (p1->next!=NULL))
 {p2=p1;                       //ʹp2ָ��ղ�p1ָ��Ľ��
  p1=p1->next;}                //p1����һ�����
  if(p0->num<=p1->num)
  {if(head==p1) head=p0;        //�嵽ԭ����һ�����֮ǰ
   else p2->next=p0;            //�嵽p2ָ��Ľ��֮��
   p0->next=p1;}
  else
  {p1->next=p0; p0->next=NULL;}}  //�嵽���Ľ��֮��
   n=n+1;                         //������ӣ�
   return (head);
}
               
void print(student *head)         //�������ĺ���
 {student *p;
  cout<<"Now��These "<<n<<" records are��"<<endl;
  p=head;
  if(head!=NULL)
  do
    {cout<<p->num<<"  "<<p->score<<endl;
     p=p->next;
	}while(p!=NULL);
}
