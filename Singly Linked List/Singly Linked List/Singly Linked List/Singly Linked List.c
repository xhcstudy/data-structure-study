#define _CRT_SECURE_NO_WARNINGS 1

#include "Singly Linked List.h"

SLTNode* BuyListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (NULL == newnode)
	{
		printf("line:%d :malloc fail\n", __LINE__);
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

SLTNode* FindTailNode(SLTNode** pphead)
{
	//�ҵ�β�ڵ�
	SLTNode* tail = *pphead;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	return tail;
}

SLTNode* FindPreNode(SLTNode** pphead, SLTNode* pos)
{
	//�ҵ�ǰһ���ڵ�
	SLTNode* pre = *pphead;
	while (pre->next != pos)
	{
		pre = pre->next;
	}
	return pre;
}

SLTNode* FindPosNode(SLTNode** pphead,SLTNode* pos)
{
	//�ҵ�pos�ڵ�
	SLTNode* pos1 = *pphead;
	while (pos1 != pos)
	{
		pos1 = pos1->next;
	}
	return pos1;
}

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode =BuyListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail =  FindTailNode(pphead);

		tail->next = newnode;
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPopBack(SLTNode** pphead)
{
	assert(*pphead != NULL);

	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = FindTailNode(pphead);
		SLTNode* pre = FindPreNode(pphead, tail);
		free(tail);
		tail = NULL;
		pre->next = NULL;
	}
}

void SListPopFront(SLTNode** pphead)
{
	assert(*pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos != NULL);
	if (pos == *pphead)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = BuyListNode(x);
		//�ҵ�posǰһ��λ��
		SLTNode* posPre = FindPreNode(pphead, pos);
		newnode->next = pos;
		posPre->next = newnode;
	}
}