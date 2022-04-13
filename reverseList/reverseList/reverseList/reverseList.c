#define _CRT_SECURE_NO_WARNINGS 1
//反转链表
//给你单链表的头节点head，请你反转链表，并返回反转后的链表
#include <stdio.h>
#include <stdlib.h>

 struct ListNode 
 {
    int val;
    struct ListNode *next;
 };

 //方法1：直接翻转
//struct ListNode* reverseList(struct ListNode* head)
//{
//	//处理空链表
//	if (head == NULL)
//	{
//		return NULL;
//	}
//	else
//	{
//		struct ListNode* pre = NULL;
//		struct ListNode* cur = head;
//		struct ListNode* next = head->next;
//		while (cur)
//		{
//			cur->next = pre;
//			pre = cur;
//			cur = next;
//			//防止next的越界访问
//			if (cur != NULL)
//			{
//				next = next->next;
//			}
//		}
//		return pre;
//	}
//}

 //2.头插
 struct ListNode* reverseList(struct ListNode* head)
 {
	 struct ListNode* newhead = NULL;
	 struct ListNode* cur = head;
	 while (cur)
	 {
		 struct ListNode* next = cur->next;
		 //头插
		 cur->next = newhead;
		 newhead = cur;
		 //迭代往后走
		 cur = next;
	 }
	return newhead;
 }