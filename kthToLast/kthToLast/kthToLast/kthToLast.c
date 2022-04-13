#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//���ص�����k���ڵ�
//ʵ��һ���㷨���ҳ����������е�����k���ڵ㡣���ظýڵ��ֵ��
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