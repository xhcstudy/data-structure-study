#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//������м�ڵ�
//����һ��ͷ�ڵ�Ϊhead�ķǿ���������������м�ڵ㡣
//����������м�ڵ㣬�򷵻صڶ����м�ڵ�


struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* slow, *fast;
	slow = fast = head;
	//�����������ʱfast��һ��  ����������ʱfastָ��β������   ż��������ʱfastΪ�ս���
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}