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

//在pos位置之前插入
void ListInsert(ListNode* pos, LTDataType x);
//删除pos位置
void ListErase(ListNode* pos);

