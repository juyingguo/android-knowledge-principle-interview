#include <iostream>
using namespace std;
#define NULL 0     
struct student
{long num;
 float score;
  student*next;
};    
int n;   
  
student *insert(student *head,student *stud)
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
   n=n+1;                              //������ӣ�
   return (head);
}
               
