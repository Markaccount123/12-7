#include"SList.h"

void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->date);
		//һ��Ҫ�μǣ����curһ������дcur++����Ϊ��ӵ�ֻ��һ��ָ��Ĵ�С����������ô�ұ�֤������һ����ַ�պ�Ϊһ��ָ��Ĵ�С����Сʱ��ȷ����
		cur = cur->next;
	}
	printf("NUll\n");
}
//����һ���½�㣬����������ں����ε��ã����Է�װһ��
SListNode* BuySListNode(SLDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("������ʧ��\n");
		exit(-1);
	}
	newNode->date = x;
	newNode->next = NULL;
	return newNode;
}
//β��
void SListPushBack(SListNode** pphead, SLDateType x)
{
	if (*pphead == NULL)
	{
		SListNode* newNode = BuySListNode(x);
		*pphead = newNode;
	}
	else
	{
		SListNode* tail = *pphead;
		//��β
		while (tail->next != NULL)
		{
			tail = tail->next;//����Ҫ���벻ͨ���Կ��μ�������Ǹ�ͼ
		}
		SListNode* newNode = BuySListNode(x);
		tail->next = newNode;
	}
}

//βɾ
void SListPopBack(SListNode** pphead)
{
	//1.��
	//2.һ�����
	//3.һ�����Ͻ��
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

//ͷ��
void SListPushFront(SListNode** pphead, SLDateType x)
{
		SListNode* newNode = BuySListNode(x);
		newNode->next= *pphead;
		*pphead = newNode;
}


//ͷɾ
void SListPopFront(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		return NULL;
	}
	else
	{
		SListNode* next = (*pphead)->next;

	}
}