#define _CRT_SECURE_NO_WARNINGS 1
#include "Singly Linked List.h"
//˳����ȱ��:
//1.�ռ䲻������Ҫ���ݣ�������Ҫ��������
//2.����Ƶ�����ݣ��������˻���������2�������ܾͻᵼ��һ���Ŀռ��˷�
//3.˳���Ҫ�����ݴӿ�ʼλ�������洢����ô������ͷ�������м�λ�ò���ɾ�����ݾ���ҪŲ�����ݣ�Ч�ʲ���
//�ŵ�:
//֧���������   -    ��Щ�㷨��Ҫ�ṹ֧��������ʣ���:���ֲ��ҡ��Ż��Ŀ���

//���˳����ȱ�ݣ�����Ƴ�������
//����
//�ŵ�
//��������ռ䣬�����˾��ͷſռ�(�������ʹ���˿ռ�)
//ͷ���м�������ݣ�����ҪŲ������
//�����ڿռ��˷�
//ȱ��:
//ÿ��һ�����ݣ���Ҫ��һ��ָ��ȥ���Ӻ�������ݽڵ�
//��֧���������(���±���ʵ�i��)

//�������ȱ�ݻ��Ǻܶ�ģ�������������ɾ��ĵ����岻��
//1.�ܶ�OJ��Ŀ����Ķ��ǵ�����
//2.������������ȥ���������ݽṹ���ӽṹ

void TestSList1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 5);
	SListPrint(plist);
	SLTNode* pos = SListFind(plist, 2);
	int i = 0;
	while (pos)
	{
		printf("��%d���ڵ�Ϊ:%p->%d\n", ++i, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}
	//�޸�
	pos = SListFind(plist, 3);
	if (pos)
	{
		pos->data = 30;
	}
	SListPrint(plist);
	//1ǰ�����һ��30
	pos = SListFind(plist, 1);
	if (pos)
	{
		SListInsert(&plist, pos, 30);
	}
	SListPrint(plist);
}
int main()
{
	TestSList1();
	return 0;
}