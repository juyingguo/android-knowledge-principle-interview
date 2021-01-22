#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


 typedef struct Node
{
	int data;//�������������������
	struct Node *pNext;//����һ���ṹ��ָ�룬ָ����һ�θ��뵱ǰ�ڵ�����������ͬ�Ľڵ�
}NODE,*PNODE;  //NODE�ȼ��� struct Node; PNODE�ȼ���struct Node *�� �˴��ô�д��Ϊ����������֣������������ױ���Ǹ���������

PNODE Create_List(void)
{
    printf("Create_List start.\n");

	int len;  //�������ĳ���
	int i;   //ѭ������
	int val;//������ʱ����û�����Ľ���ֵ
	PNODE List;
	PNODE pHead=(PNODE)malloc(sizeof(NODE));//����һ��ͷ�ڵ�
	if(NULL==pHead)
	{
		printf("Memory allocation failure");
		exit(-1);
	}
	else
	{   PNODE pTail=pHead;

        printf("Create_List pHead= %x,pTail = %x\n",pHead,pTail);

		pHead->pNext=NULL;
		printf("please input the length of list: ");  //��Ҫһ��ָ��ʼ��ָ������Ľ�β
		scanf("%d",&len);
		for(i=0;i<len;i++)
		{
		    PNODE p=(PNODE)malloc(sizeof(NODE));
		    if(NULL==p)
	        {
		        printf("Memory allocation failure");
		        exit(-1);
	        }
			else
			{
				printf("please input the value of list: ");
				scanf("%d",&val);
				p->data=val;
				pTail->pNext=p;
				p->pNext=NULL;
				pTail=p;
			}
            printf("Create_List i=%d , pHead= %x,pTail = %x\n",i,pHead,pTail);

		}


	}
	return pHead;

}
//����ĵ�pos��ЧԪ��ǰ�����Ԫ��val����������Ӧ���ҵ���pos��Ԫ��ǰ��һ��Ԫ�ص�λ�ã�
//��������3��Ԫ��ʱ��pos=4����������в������
bool Insert_List(PNODE pHead,int pos,int val)
{
	int i=0;
	PNODE p=pHead;
	while((NULL!=p)&&(i<pos-1)) //
	{
		p=p->pNext;
		i++;
	}
	if(p==NULL||i>pos-1)  //������Ϊ�յ�������ǽ�ȥ�ˣ�i>pos-1 ���Է�ֹ�û��������
		return false;

	//����ִ�е���֮��i=pos-1��pָ��ָ�������pos����Ч�ڵ��ǰ������ָ���pos-1�ڵ㣻
	PNODE q=(PNODE)malloc(sizeof(NODE));
	q->data=val;
	q->pNext=p->pNext;
	p->pNext=q;


}

bool Delete_List(PNODE pHead,int pos,int *val)
{
	int i=0;
	PNODE p=pHead;
	while((NULL!=p)&&(i<pos-1))
	{
		p=p->pNext;
		i++;
	}
	if(p==NULL||i>pos-1)  //������Ϊ�յ�������ǽ�ȥ�ˣ�i>pos-1 ���Է�ֹ�û��������
		return false;

	//����ִ�е���֮��i=pos-1��
	PNODE q=p->pNext;  //qָ���ɾ���Ľڵ㣻
	*val=q->data;
	p->pNext=q->pNext; //�޸�����ָ��ָ��
	free(q);           //�ͷ�q��ָ��ڵ���ڴ棻
	q=NULL;//ǧ�򲻿������ǣ���������Ұָ�룻
}
//������ЧԪ�صĸ���
int Length_List(PNODE pHead)
{   int len=0;  //�������Ҫ�ǵó�ʼ����
    PNODE p=pHead->pNext;
	while(NULL!=p)
	{
		len++;
		p=p->pNext;
	}
	return len;

}

//�������е�Ԫ�ؽ�������
void Sort_List(PNODE pHead)
{
	int i,j;
	int temp;
	int len=Length_List(pHead);
	PNODE p,q;//ָ�������һ����ЧԪ��

	for(i=0,p=pHead->pNext;i<len-1;i++,p=p->pNext)
	{
		for(j=i+1,q=p->pNext;j<len;j++,q=q->pNext)
		{
			//��������
			if(p->data>q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}
	}
}

int main(void)
{
   PNODE list = Create_List();
   int length_list = Length_List(list);
   printf("main length_list= %d:\n",length_list);
   return 0;
}


