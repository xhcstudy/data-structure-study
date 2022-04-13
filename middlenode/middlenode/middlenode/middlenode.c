#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//链表的中间节点
//给定一个头节点为head的非空链表，返回链表的中间节点。
//如果有两个中间节点，则返回第二个中间节点


struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* slow, *fast;
	slow = fast = head;
	//两种情况结束时fast不一样  奇数个数据时fast指向尾部结束   偶数个数据时fast为空结束
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}