#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int SLDateType;
//���
//����洢�ķ�ʽӦ�������ݺ�ָ�룬ͨ��ָ����������������һ��
//(��ʱͷ�岻����ҪŲ�����ݣ��ҿ���ֱ������һ���ռ䣬����һ��ָ����Ǹ�����)
typedef struct SListNode
{
	SLDateType date;
	struct SListNode* next; //(��ʵ����ṹ��ָ������������һ����Ҫ���ʵĵ�ַ)
}SListNode; 

//�������β��
void SListPushBack(SListNode** phead, SLDateType x);

//βɾ
void SListPopBack(SListNode** phead);

//ͷ��
void SListPushFront(SListNode** pphead, SLDateType x);

//ͷɾ
void SListPopFront(SListNode** phead);

//��ӡ
void SListPrint(SListNode* phead);

