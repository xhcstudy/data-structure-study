#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newlistnode = (ListNode*)malloc(sizeof(ListNode));
	newlistnode->data = x;
	newlistnode->next = NULL;
	newlistnode->prev = NULL;
	return newlistnode;
}

void ListInit(ListNode** pphead)
{
	//�ڱ�λͷ�ڵ�
	ListNode* phead = (ListNode*)malloc(sizeof(ListNode));
	phead->next = phead;
	phead->prev = phead;
	*pphead = phead;
}

void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);

	//ListNode* tail = phead->prev;
	//ListNode* newlistnode = BuyListNode(x);
	////β��
	//tail->next = newlistnode;
	//newlistnode->prev = tail;
	//newlistnode->next = phead;
	//phead->prev = newlistnode;
	//tail = newlistnode;

	ListInsert(phead, x);
}

void ListPopBack(ListNode* phead)
{
	assert(phead);
	//���ܰ��ڱ�λɾ��
	assert(phead->next != phead);

	//ListNode* tail = phead->prev;
	//phead->prev = tail->prev;
	//tail->prev->next = phead;
	//free(tail);

	ListErase(phead->prev);
}

void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	//ListNode* newlistnode = BuyListNode(x);
	//ListNode* next = phead->next;
	//phead->next = newlistnode;
	//newlistnode->prev = phead;
	//newlistnode->next = next;
	//next->prev = newlistnode;

	ListInsert(phead->next, x);
}

void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	//ListNode* next = phead->next;
	//next->next->prev = phead;
	//phead->next = next->next;
	//free(next);

	ListErase(phead->next);
}

ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//��posλ��֮ǰ����
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* newlistnode = BuyListNode(x);
	newlistnode->prev = posPrev;
	newlistnode->next = pos;
	posPrev->next = newlistnode;
	pos->prev = newlistnode;
}

//ɾ��posλ��
void ListErase(ListNode* pos)
{
	assert(pos);
	assert(pos->next != pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
}

void ListDestroy(ListNode* phead)
{
	assert(phead);
	struct ListNode* cur = phead->next;
	while (cur != phead)
	{
		struct ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
}