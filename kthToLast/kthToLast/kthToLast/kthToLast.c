#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//返回倒数第k个节点
//实现一种算法，找出单向链表中倒数第k个节点。返回该节点的值。
struct ListNode 
{
	int val;
	struct ListNode *next;
};

int kthToLast(struct ListNode* head, int k)
{
	struct ListNode* slow, *fast;
	slow = fast = head;
	while (k--)
	{
		fast = fast->next;
	}
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow->val;
}