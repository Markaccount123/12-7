#include"SList.h"

int main()
{
	//SListNode* pList = NULL;  // ����ͱ�ʾ������
	SListNode* phead = NULL;//ֻ����һ��ͷָ��
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPrint(phead);

	//SListPopBack(&phead);
	//SListPrint(phead);
	//SListPopBack(&phead);
	//SListPrint(phead);
	//SListPopBack(&phead);
	//SListPrint(phead);
	//SListPopBack(&phead);
	//SListPrint(phead);

	SListPopFront(phead);
	SListPrint(phead);
	return 0;
}





