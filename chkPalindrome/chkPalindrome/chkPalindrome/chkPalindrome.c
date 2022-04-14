#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//链表的回文结构
//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。

struct ListNode 
{
	int val;
	struct ListNode *next;
}; 

//定义返回1为回文结构，返回0不是
int chkPalindrome(struct ListNode* A) 
{
	struct ListNode* slow, *fast, *cur2;
	slow = fast = A;
	//找中间节点
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//将后面的节点逆置得到新链表
	cur2 = slow;
	struct ListNode* newhead = NULL;
	while (cur2)
	{
		struct ListNode* next = cur2->next;
		cur2->next = newhead;
		newhead = cur2;
		cur2 = next;
	}
	struct ListNode* cur1 = A;
	cur2 = newhead;
	//与前面的链表比较
	while (cur1 && cur2)
	{
		if (cur1->val != cur2->val)
		{
			return 0;
		}
		else
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
	}
	return 1;
}