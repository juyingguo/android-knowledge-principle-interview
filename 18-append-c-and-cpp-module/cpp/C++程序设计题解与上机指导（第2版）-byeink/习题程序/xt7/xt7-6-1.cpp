#include <iostream>
using namespace std;
#define NULL 0     
struct student
{long num;
 float score;
 struct student *next;
};
int main()
 {student a,b,c,*head,*p;
  a.num=10001; a.score=89.5;
  b.num=10003; b.score=90;
  c.num=10007; c.score=85;     //Ϊ����num��score��Ա��ֵ
  head=&a;                      //�����a����ʼ��ַ����ͷָ��head
  a.next=&b;                    //�����b����ʼ��ַ����a����next��Ա
  b.next=&c;                    //�����c����ʼ��ַ����b����next��Ա
  c.next=NULL;                  //c����next��Ա�������������ַ
  p=head;                       //ʹpָ��ָ��a���
  do        
   {cout<<p->num<<"  "<<p->score<<endl; //���pָ��Ľ�������
    p=p->next;                                //ʹpָ����һ���
   }while(p!=NULL);                          //�����c����p��ֵΪNULL
  return 0;
}

