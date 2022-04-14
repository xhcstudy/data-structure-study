#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//合并两个有序链表
//将两个升序链表合并为一个新的升序链表返回，新链表是通过拼接给定的两个链表的所有节点组成的。
//归并的思路

struct ListNode 
{
	int val;
	struct ListNode *next;
};

//不带哨兵位的头节点
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//	struct ListNode* tail, *cur1, *cur2, *newhead;
//	cur1 = list1;
//	cur2 = list2;
//	//如果有一个链表为空，直接返回另外一个链表
//	if (cur1 == NULL)
//	{
//		return cur2;
//	}
//	if (cur2 == NULL)
//	{
//		return cur1;
//	}
//	//确定新链表头节点
//	if (cur1->val <= cur2->val)
//	{
//		newhead = cur1;
//		tail = cur1;
//		cur1 = cur1->next;
//	}
//	else
//	{
//		newhead = cur2;
//		tail = cur2;
//		cur2 = cur2->next;
//	}
//	//排序
//	while (cur1 && cur2)
//	{
//		if (cur1->val <= cur2->val)
//		{
//			tail->next = cur1;
//			tail = cur1;
//			cur1 = cur1->next;
//		}
//		else
//		{
//			tail->next = cur2;
//			tail = cur2;
//			cur2 = cur2->next;
//		}
//	}
//	//一个链表走完之后直接将另外一个链表剩下元素链接在新链表尾部
//	if (cur1 == NULL)
//	{
//		tail->next = cur2;
//	}
//	else
//	{
//		tail->next = cur1;
//	}
//	return newhead;
//}


//带哨兵位的头节点
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	struct ListNode* tail, *cur1, *cur2, *newhead;
	cur1 = list1;
	cur2 = list2;
	//如果有一个链表为空，直接返回另外一个链表
	if (cur1 == NULL)
	{
		return cur2;
	}
	if (cur2 == NULL)
	{
		return cur1;
	}
	//哨兵位的头节点
	newhead = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
	//排序
	while (cur1 && cur2)
	{
		if (cur1->val <= cur2->val)
		{
			tail->next = cur1;
			tail = cur1;
			cur1 = cur1->next;
		}
		else
		{
			tail->next = cur2;
			tail = cur2;
			cur2 = cur2->next;
		}
	}
	//一个链表走完之后直接将另外一个链表剩下元素链接在新链表尾部
	if (cur1 == NULL)
	{
		tail->next = cur2;
	}
	else
	{
		tail->next = cur1;
	}
	struct ListNode* list = newhead->next;
	free(newhead);
	return list;
}