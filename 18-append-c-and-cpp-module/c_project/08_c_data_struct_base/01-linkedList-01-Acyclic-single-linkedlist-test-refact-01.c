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
		printf("Create_List pHead->pNext= %x \n",pHead->pNext);
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
            printf("Create_List pHead->pNext= %x \n",pHead->pNext);

		}


	}
	return pHead;

}
/**
����ͷ�巨��
����ĵ�pos��ЧԪ��ǰ�����Ԫ��val����������Ӧ���ҵ���pos��Ԫ��ǰ��һ��Ԫ�ص�λ�ã�
��������3��Ԫ��ʱ��pos=4����������в������

*/
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

    return true;
}
/**
pos>=1 ��pos<=n;pos��ΪҪɾ���ĵڼ���Ԫ�أ���ʱ��������1��ʼ��
*/
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
	return true;
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

    printf("Length_List len= %d \n",len);
	return len;

}
/**
    ����������ӡ��ֵ��
*/
void print_List(PNODE pHead)
{   int i=0;  //�������Ҫ�ǵó�ʼ����
    PNODE p=pHead->pNext;

	while(NULL!=p)
	{
		i++;
        printf("print_List current node number i=%d , p->data = %d\n",i,p->data);

		p=p->pNext;
	}


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
//   PNODE list = Create_List();
//   int length_list = Length_List(list);
//   printf("main length_list= %d:\n",length_list);
//
//   print_List(list);
//
//   if(length_list >=2){
//        int delVal = -1;
//        printf("when length_list >=2 delete node of number 2\n");
//        Delete_List(list,2,&delVal);
//
//        length_list = Length_List(list);
//        printf("main current length_list= %d:\n",length_list);
//        printf("delete node it's value is %d\n",delVal);
//
//        print_List(list);
//   }
    PNODE pHead = NULL;

    printf("********************************************\n");
	printf("*                  ���ܲ˵�                *\n");
	printf("* 1 ������������         2 ����λ�ò�����*\n");
	printf("* 3 ��ӡ�����������     4 ��ӡ��������    *\n");
	printf("* 5 ɾ��ĳ���           6 ��������        *\n");
	printf("* 7                      8                 *\n");
	printf("* 9                      10 �˳�           *\n");
	printf("********************************************\n");
	while(1)
	{
		int choice;
		printf("�����빦����ţ�");
		scanf("%d" ,&choice);
		switch(choice)
		{
		case 1:
			{
				pHead = Create_List();
				break;
			}
		case 2:
			{
				int pos, val;
				printf("������Ҫ�����λ�ú�ֵ(��������֮���ÿո�ֿ�)��");
				scanf("%d %d", &pos, &val);
				Insert_List(pHead,pos, val);
				break;
			}
		case 3:
			{

				Length_List(pHead);
				break;
			}
		case 4:
			{
			    print_List(pHead);
				break;
			}
		case 5:
			{
                int pos, val;
				printf("������Ҫɾ����λ�ã�");
				scanf("%d", &pos);
				Delete_List(pHead,pos, val);
				break;
			}
		case 6:
			{
                Sort_List(pHead);
				break;
			}
		case 7:
			{

				break;
			}
		case 8:
			{

				break;
			}
        case 9:
            {

                break;
            }
        case 10:
            {
                exit(0);
            }
		default:
			printf("error");
		}
	}
   return 0;
}


