#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。

struct ListNode 
{
	int val;
	struct ListNode *next;
};

//用两个链表，一个尾插小于x节点，一个尾插大于x的节点  最后两个链表链接
struct ListNode* partition(struct ListNode* pHead, int x)
{
	struct ListNode* lessHead, *greaterHead, *lessTail, *greaterTail, *cur;
	cur = pHead;
	lessHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	greaterHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	lessTail = lessHead;
	greaterTail = greaterHead;
	lessTail->next = NULL;
	greaterTail->next = NULL;
	while (cur)
	{
		if (cur->val < x)
		{
			lessTail->next = cur;
			lessTail = cur;
			cur = cur->next;
		}
		else
		{
			greaterTail->next = cur;
			greaterTail = cur;
			cur = cur->next;
		}
	}
	//合并两个链表
	lessTail->next = greaterHead->next;
	greaterTail->next = NULL;
	struct ListNode* newhead = lessHead->next;
	free(lessHead);
	free(greaterHead);
	return newhead;
}