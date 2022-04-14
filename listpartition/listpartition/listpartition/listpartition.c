#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//����һ�����ͷָ�� ListNode* pHead����һ��ֵx����дһ�δ��뽫����С��x�Ľ������������֮ǰ���Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣

struct ListNode 
{
	int val;
	struct ListNode *next;
};

//����������һ��β��С��x�ڵ㣬һ��β�����x�Ľڵ�  ���������������
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
	//�ϲ���������
	lessTail->next = greaterHead->next;
	greaterTail->next = NULL;
	struct ListNode* newhead = lessHead->next;
	free(lessHead);
	free(greaterHead);
	return newhead;
}