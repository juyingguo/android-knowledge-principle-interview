#include<stdio.h>
#include<malloc.h>

#define ElemType int

typedef struct LinkNode{
	ElemType data;
	struct LinkNode *pNext;
}LinkNode;

LinkNode *pHead = NULL;   //���������ͷָ��
LinkNode *pEnd = NULL;    //���������βָ��

//������������ڵ�
void CreateNode(LinkNode *pNode)
{
	if(NULL != pNode)
	{
		printf("�����������ݣ�");
		scanf("%d", &pNode->data);
	}
	pNode->pNext = NULL;
}


//��������������ͷ�ڵ㣩,�������Ϊ����һ���ձ�������������ֻ����һ��ͷ���
void CreateLinkList()
{
        printf("int type storage sizeof(char) = %d:\n",sizeof(char));
        printf("CreateLinkList(),sizeof(int) = %d \n",sizeof(int));
        printf("int type storage sizeof(int) = %d:\n",sizeof(int));
        printf("CreateLinkList(),sizeof(int(*)) = %d \n" ,sizeof(int(*)));
        printf("CreateLinkList(),sizeof(size_t) = %d \n", sizeof(size_t));
        printf("CreateLinkList(),sizeof(LinkNode) = %d \n" ,sizeof(LinkNode));
        printf("CreateLinkList(),sizeof(LinkNode(*)) = %d \n" ,sizeof(LinkNode(*)));

        printf("int type storage sizeof(pHead) = %d:\n",sizeof(pHead));
		LinkNode *pNew = malloc(sizeof(LinkNode));
		pNew->data = NULL;    //ͷ��㲻��Ԫ��
		pNew->pNext = NULL;

		pHead = pNew;//��ͷ��βָ�붼ָ��ͷ���
		pEnd = pNew;
		pEnd->pNext = pHead;//βָ���ָ����ָ��ͷָ�롣

		printf("CreateLinkList(),NULL=%d\n",NULL);
		printf("CreateLinkList(),pHead->data=%d\n",pHead->data);
		printf("CreateLinkList(),pNew->pNext=%x\n",pNew->pNext);

		//��ӡ������ֵ��ͬ��pHead,pHead->pNext��pEnd->pNext
		printf("CreateLinkList(),pHead=%x\n",pHead);
		printf("CreateLinkList(),pHead->pNext=%x\n",pHead->pNext);
        printf("CreateLinkList(),pEnd->pNext=%x\n",pEnd->pNext);
		printf("��������ɹ�!\n");
}

//��ӽ�㣬���������ΰ�˳����ӣ�ע�������Ĳ��������ֿ�
void AddNode()
{
		LinkNode *pNew = malloc(sizeof(LinkNode));
		CreateNode(pNew);

		pEnd->pNext = pNew;
		pEnd = pNew;

		//��ӽ���ͷָ���β����ָ�����Ƕ�����һ��������Ҫ�ٴ�ָ����
		//��ӡ�����ֵ�ǲ�һ���ġ�����Ҫ�ٴΡ���ͬ˵���ǿձ����������жϿձ�
		printf("��ӽ���ͷָ���β����ָ�����Ƕ�����һ��������Ҫ�ٴ�ָ����!\n");
		printf("AddNode(),pHead=%x\n",pHead);
        printf("AddNode(),pEnd->pNext=%x\n",pEnd->pNext);
		printf("��ӽ��ɹ�!\n");
}

//�����������
void ShowLinkList()
{
	if(pHead != pHead->pNext)  //  ѭ����������ж�Ϊ�յ���������ͷ����ָ���Ƿ�Ϊ�գ��������Ƿ����ͷָ��
	{
		LinkNode *pTemp = pHead->pNext;  //pTempָ��ָ���׽�㣬�׽��Ϊͷ������һ�����
		printf("����ĵ�������Ϊ��");
		while(NULL != pTemp)
		{
			printf("%d ", pTemp->data);
			pTemp = pTemp->pNext;
		}
	}
	else
	{
		printf("��������Ϊ�ձ�!\n");
	}
}

//���������в���ĳ�����
LinkNode* FindNode(ElemType e, LinkNode **ppLast)   //eΪ��������,�ڶ���������Ҫ��ָ�������ҽڵ��ǰһ����㣬�������Ĳ��뺯���ı�д���ò����õ���ָ���ָ�롣
{
    printf("FindNode,e= %d!\n",e);
	if(pHead != pHead->pNext)
	{
		LinkNode *pTemp = pHead;
		while(NULL != pTemp)
		{
			if(pTemp->data != NULL && e == pTemp->data)
			{//ע�����e=0��ͷ����������Ϊ�յ�(NULL��Ӧ��ֵҲ��0)���͵����ҵ���ͷָ�롣�Ǵ���ġ�
			    //������Ҫ�����ж�������pTemp->pNext != NULL��ͷָ��������򲻲���Ƚ�
                printf("FindNode,success,pTemp->data= %d!\n",pTemp->data);
				return pTemp;
			}
			if(NULL != ppLast)
			{
				*ppLast = pTemp;
			}
			pTemp = pTemp->pNext;
		}
	}
	printf("FindNode,can't get note with input data!\n");
	return NULL;
}

//�޸ĵ�������ĳһ����ֵ
void ModifyNode(ElemType e)
{
	if(pHead != pHead->pNext)
	{
		LinkNode *pNode = FindNode(e, NULL);//�ڶ�����������NULL���ɡ�
		printf("�������޸ĺ�Ľ�����ݣ�");
		scanf("%d",&pNode->data);
		printf("�޸Ľ�����ݳɹ�!\n");
	}
}

/**
���������ض�λ�ò����㡣ע�⣺��ʱ��λ�ò����������ǽڵ��������ֵ��
 eΪ������Ӧ��ֵ��nType��ʾ����ķ�ʽ�����ǹ涨nType=0Ϊǰ�壬nType=1Ϊ���
**/
void InsertNode(ElemType e, int nType)
{
	if(pHead != pHead->pNext)
	{
		LinkNode *pLast = NULL;   //��¼����λ�õ�ǰһ�����
		LinkNode *pPos = FindNode(e, &pLast);   //�ڶ���������ָ���ָ�룬��Ҫ��Ϊ�������βε�ֵ�ı�ʵ�ε�ֵ��˳����pLastָ������ȷ��ָ��

		if(pPos == NULL){
            printf("InsertNode,pPos == NULL(FindNode return NULL node with input data) ,can't insert.\n");
            return;
		}

		LinkNode *pNew = malloc(sizeof(LinkNode));
		CreateNode(pNew);
		if(0 == nType)  //ǰ��
		{
                if(pLast == NULL){//����ǰ�巨�����pLast=NULL���޷����롣���ӷǿ��жϡ�
                    printf("����ڵ�ʧ��,pLast == NULL �޷�����!\n");
                }else{
                    pLast->pNext = pNew;
                    pNew->pNext = pPos;
                }
		}
		else  //���
		{
				pNew->pNext = pPos->pNext;
				pPos->pNext = pNew;

				//���ں�巨�����д�����·�ʽ��������½ڵ��ָ����ָ�����Լ���������������нڵ㶪ʧ��
//                pPos->pNext = pNew;
//                pNew->pNext = pPos->pNext;
		}
		printf("������ɹ�!\n");
	}else{
        printf("��������Ϊ�ձ�!\n");
	}
}


//ɾ����������ĳһ���
void DeleteNode(ElemType e)
{
	if(pHead != pHead->pNext)
	{
		LinkNode *pLast = NULL;
		LinkNode *pPos = FindNode(e, &pLast);
		if(NULL != pPos)
		{
			pLast->pNext = pPos->pNext;
			free(pPos);   //�ͷ��ڴ�ռ�
			printf("ɾ�����ɹ�!\n");
		}
		else
		{
			printf("��Ҫɾ���Ľ�㲻����!");
		}
	}else{
        printf("��������Ϊ�ձ�!\n");
	}
}

//ɾ��������������
void ClearLinkList()
{
	if(pHead != pHead->pNext)
	{
		LinkNode *pClear = pHead->pNext;
		LinkNode *pTemp = NULL;

		while(NULL != pClear)
		{
			pTemp = pClear->pNext;
			free(pClear);
			pClear = pTemp;
		}
		pHead->pNext = pHead;
		pEnd->pNext = pHead;
		printf("�������ɹ�!\n");
	}
}
/**

*/
LinkNode * printLastNote(){
    if(pHead != pHead->pNext)
	{
		LinkNode *pTemp = pHead;
		LinkNode *pLast = NULL;
		while(pTemp != NULL){
            pLast = pTemp;
            pTemp = pTemp->pNext;
		}
		printf("printLastNote(),pTemp=%x\n",pTemp);
		printf("printLastNote(),pHead=%x\n",pHead);
		printf("printLastNote(),pLast=%x\n",pLast);
		printf("printLastNote(),pLast->pNext=%x\n",pLast->pNext);
		return pLast;
	}
	printf("printLastNote(),pHead->pNext=%d\n",pHead->pNext);
	return pHead->pNext;
}


int main()
{
	printf("********************************************\n");
	printf("*                  ���ܲ˵�                *\n");
	printf("* 1 ������������           2 ˳������½��*\n");
	printf("* 3 �޸Ľ��               4 ���ҽ��      *\n");
	printf("* 5 ����λ�ò�����       6 ɾ��ĳ���    *\n");
	printf("* 7 ���������������       8 ��ӡ��������  *\n");
	printf("* 9 ��ӡ���һ���ڵ���Ϣ   10 �˳�         *\n");
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
				CreateLinkList();
				break;
			}
		case 2:
			{
				AddNode();
				break;
			}
		case 3:
			{
				int e;
				printf("������Ҫ�޸ĵĽ�㣺");
				scanf("%d", &e);
				ModifyNode(e);
				break;
			}
		case 4:
			{
				break;
			}
		case 5:
			{
				int e, type;
				printf("������Ҫ�����λ�úͲ��뷽ʽ(��������֮���ÿո�ֿ�)��");
				scanf("%d %d", &e, &type);
				InsertNode(e, type);
				break;
			}
		case 6:
			{
				int e;
				printf("������Ҫɾ���Ľ�㣺");
				scanf("%d", &e);
				DeleteNode(e);
				break;
			}
		case 7:
			{
				ClearLinkList();
				break;
			}
		case 8:
			{
				ShowLinkList();
				break;
			}
        case 9:
            {
                printLastNote();
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
