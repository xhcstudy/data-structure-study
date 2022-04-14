#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//����Ļ��Ľṹ
//����һ�����������һ��ʱ�临�Ӷ�ΪO(n), ����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��

struct ListNode 
{
	int val;
	struct ListNode *next;
}; 

//���巵��1Ϊ���Ľṹ������0����
int chkPalindrome(struct ListNode* A) 
{
	struct ListNode* slow, *fast, *cur2;
	slow = fast = A;
	//���м�ڵ�
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//������Ľڵ����õõ�������
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
	//��ǰ�������Ƚ�
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