#define _CRT_SECURE_NO_WARNINGS 1
//��ת����
//���㵥�����ͷ�ڵ�head�����㷴ת���������ط�ת�������
#include <stdio.h>
#include <stdlib.h>

 struct ListNode 
 {
    int val;
    struct ListNode *next;
 };

 //����1��ֱ�ӷ�ת
//struct ListNode* reverseList(struct ListNode* head)
//{
//	//���������
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
//			//��ֹnext��Խ�����
//			if (cur != NULL)
//			{
//				next = next->next;
//			}
//		}
//		return pre;
//	}
//}

 //2.ͷ��
 struct ListNode* reverseList(struct ListNode* head)
 {
	 struct ListNode* newhead = NULL;
	 struct ListNode* cur = head;
	 while (cur)
	 {
		 struct ListNode* next = cur->next;
		 //ͷ��
		 cur->next = newhead;
		 newhead = cur;
		 //����������
		 cur = next;
	 }
	return newhead;
 }