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
  head=creat();                        //返回头指针
  print(head);                          //输出全部结点
  cout<<endl<<"input the deleted number:";
  cin>>del_num;                        //输入要删除的学号
  while(del_num!=0)
  {head=del(head,del_num);              //删除后链表的头地址
   print(head);                         //输出全部结点
   cout<<"input the deleted number:";
   cin>>del_num; 
  }
  cout<<endl<<"input the inserted record:";  //输入要插入的结点
  stu=new student;                      //开辟一个新结点
  cin>>stu->num>>stu->score;
  while(stu->num!=0)
  {head=insert(head,stu);              //返回地址
   print(head);                         //输出全部结点
   cout<<endl<<"input the inserted record:";  //输入要插入的结点
   stu=new student;
   cin>>stu->num>>stu->score;
  }
  return 0;
}

student *creat(void)       //建立链表的函数
{student *head;
 student *p1,*p2;
 n=0;
 p1=p2=new student;       //开辟一个新单元，并使p1,p2指向它
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

student *del(student *head,long num)   //删除结点的函数
{student *p1,*p2;
 if (head==NULL)                    //是空表
 {cout<<"list null!"<<endl; return(head);}
 p1=head;                          //使p1指向第一个结点
 while(num!=p1->num && p1->next!=NULL) //p1指向的不是所要找的结点且后面还有结点
 {p2=p1; p1=p1->next;}                 //p1后移一个结点
 if(num==p1->num)                        //找到了
 {if(p1==head) head=p1->next;   //若p1指向的是首结点，把第二个结点地址赋予head
  else p2->next=p1->next;    //否则将下一结点地址赋给前一结点地址
  cout<<"delete:"<<num<<endl;
  n=n-1;
 }
 else cout<<"cannot find "<<num;     //找不到该结点
 return(head);
}
    
student *insert(student *head,student *stud)  //插入结点的函数
{student *p0,*p1,*p2;
 p1=head;                          //使p1指向第一个结点
 p0=stud;                          //指向要插入的结点
 if(head==NULL)                    //原来的链表是空表
 {head=p0;p0->next=NULL;}          //使p0指向的结点作为头结点
 else
 {while((p0->num>p1->num) && (p1->next!=NULL))
 {p2=p1;                       //使p2指向刚才p1指向的结点
  p1=p1->next;}                //p1后移一个结点
  if(p0->num<=p1->num)
  {if(head==p1) head=p0;        //插到原来第一个结点之前
   else p2->next=p0;            //插到p2指向的结点之后
   p0->next=p1;}
  else
  {p1->next=p0; p0->next=NULL;}}  //插到最后的结点之后
   n=n+1;                         //结点数加１
   return (head);
}
               
void print(student *head)         //输出链表的函数
 {student *p;
  cout<<"Now，These "<<n<<" records are："<<endl;
  p=head;
  if(head!=NULL)
  do
    {cout<<p->num<<"  "<<p->score<<endl;
     p=p->next;
	}while(p!=NULL);
}
