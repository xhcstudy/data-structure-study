#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//�ϲ�������������
//��������������ϲ�Ϊһ���µ����������أ���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
//�鲢��˼·

struct ListNode 
{
	int val;
	struct ListNode *next;
};

//�����ڱ�λ��ͷ�ڵ�
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//	struct ListNode* tail, *cur1, *cur2, *newhead;
//	cur1 = list1;
//	cur2 = list2;
//	//�����һ������Ϊ�գ�ֱ�ӷ�������һ������
//	if (cur1 == NULL)
//	{
//		return cur2;
//	}
//	if (cur2 == NULL)
//	{
//		return cur1;
//	}
//	//ȷ��������ͷ�ڵ�
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
//	//����
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
//	//һ����������֮��ֱ�ӽ�����һ������ʣ��Ԫ��������������β��
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


//���ڱ�λ��ͷ�ڵ�
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	struct ListNode* tail, *cur1, *cur2, *newhead;
	cur1 = list1;
	cur2 = list2;
	//�����һ������Ϊ�գ�ֱ�ӷ�������һ������
	if (cur1 == NULL)
	{
		return cur2;
	}
	if (cur2 == NULL)
	{
		return cur1;
	}
	//�ڱ�λ��ͷ�ڵ�
	newhead = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
	//����
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
	//һ����������֮��ֱ�ӽ�����һ������ʣ��Ԫ��������������β��
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