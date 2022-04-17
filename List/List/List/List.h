#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

void ListInit(ListNode** pphead);
void ListPrint(ListNode* phead);
ListNode* ListFind(ListNode* phead, LTDataType x);
void ListDestroy(ListNode* phead);

void ListPushBack(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);

void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);

//��posλ��֮ǰ����
void ListInsert(ListNode* pos, LTDataType x);
//ɾ��posλ��
void ListErase(ListNode* pos);

