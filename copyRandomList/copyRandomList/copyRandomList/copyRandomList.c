#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//���ƴ����ָ�������
//����һ������Ϊn������ÿ���ڵ����һ���������ӵ����ָ��random����ָ�����ָ�������е��κνڵ��սڵ㡣
//��������������������Ӧ��������n��ȫ�½ڵ���ɣ�����ÿ���½ڵ��ֵ����Ϊ���Ӧ��ԭ�ڵ��ֵ��
//�½ڵ��next ָ���random ָ��Ҳ��Ӧָ���������е��½ڵ㣬��ʹԭ����͸��������е���Щָ���ܹ���ʾ��ͬ������״̬��
//���������е�ָ�붼��Ӧָ��ԭ�����еĽڵ㡣
//���磬���ԭ��������X��Y�����ڵ㣬����X.random-->Y����ô�ڸ��������ж�Ӧ�������ڵ�x��y��ͬ����x.random-->y��
//���ظ��������ͷ�ڵ㡣
//��һ����n���ڵ���ɵ���������ʾ���� / ����е�����ÿ���ڵ���һ��[va1, random_index]��ʾ:
//va1 : ������ʾNode.val��������
//random_index : ���ָ��ָ��Ľڵ�����(��Χ�� 0 �� n - 1 ); �����ָ���κνڵ㣬��Ϊnul1��
//��Ĵ���ֻ����ԭ�����ͷ�ڵ�head��Ϊ���������

//˼·:
//1.��ԭ�ڵ�������һ���ڵ���Ϊԭ�ڵ����ʱ����
//2.�ڿ����ڵ��ϴ���random���� �����ڵ��random = ԭ�ڵ�random����һ��
//3.�������ڵ�������������ӳ�Ϊһ����������������������������ҽ�ԭ����ָ�����
struct Node 
{
	int val;
	struct Node *next;
	struct Node *random;
};

struct Node* copyRandomList(struct Node* head)
{
	struct Node* cur = head;
	//1.����ڵ�
	while (cur)
	{
		struct Node* next = cur->next;
		struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
		copy->val = cur->val;
		//����
		cur->next = copy;
		copy->next = next;
		cur = next;
	}
	//2.���ÿ����ڵ㴦��random
	cur = head;
	while (cur)
	{
		struct Node* copy = cur->next;
		struct Node* next = copy->next;
		if (cur->random == NULL)
		{
			copy->random = NULL;
		}
		else
		{
			copy->random = cur->random->next;
		}
		cur = next;
	}
	//3.���¿����ڵ�Ȼ�󽫿����ڵ����ӳ��������һָ�ԭ����
	struct Node* newlisthead = NULL;
	struct Node* newlisttail = NULL;
	cur = head;
	while (cur)
	{
		struct Node* copy = cur->next;
		struct Node* next = copy->next;
		//����������
		if (newlisthead == NULL)
		{
			newlisthead = copy;
			newlisttail = copy;
		}
		else
		{
			newlisttail->next = copy;
			newlisttail = copy;
		}
		//�ָ�ԭ����
		cur->next;
		cur = next;
	}
	return newlisthead;
}