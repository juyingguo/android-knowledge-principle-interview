#include <iostream>
using namespace std;
#define NULL 0     
struct student
{long num;
 float score;
 student *next;
};    
int n;     
student *del(student *head,long num)
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
               
