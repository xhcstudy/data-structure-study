#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//��������

//����һ�������ͷ�ڵ�head���ж��������Ƿ��л���
//�����������ĳ���ڵ㣬����ͨ����������nextָ���ٴε���������д��ڻ���
//Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������pos����ʾ����β���ӵ������е�λ��(������0��ʼ)��
//ע��:pos����Ϊ�������д��ݡ�������Ϊ�˱�ʶ�����ʵ�����������������л�����true�����򷵻�false��

//˼·:����ָ������ ʹ��һ��slow �� fastָ�� slow��һ����fast����������������� fast���ߵ��գ�������� fast��׷��slow

struct ListNode 
{
	int val;
	struct ListNode *next;
};

//����л�����1��û������0
int hasCycle(struct ListNode *head) 
{
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			return 1;
		}
	}
	return 0;
}


//��������:
//1��Ϊʲôslow��fastһ�����ڻ������� ? �᲻���ڻ�����������Զ������ ? ��֤��һ��
//���� : ����һ����������������Ҫ����֤��һ�¡�
//2��Ϊʲôslow��һ����fast�ߵ������� ? �ܲ���fast��һ����n��(n > 2) ? ��֤��һ��
//���� : fastһ����n�� , n > 2��һ��������
