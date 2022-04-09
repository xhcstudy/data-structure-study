#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1.���Ա�
//���Ա�(linear list)��n��������ͬ���Ե�����Ԫ�ص��������С����Ա���һ����ʵ���й㷺ʹ�õ����ݽṹ�����������Ա�:˳�������ջ�����С��ַ���...
//���Ա����߼��������Խṹ��Ҳ��˵��������һ��ֱ�ߡ�����������ṹ�ϲ���һ���������ģ����Ա��������ϴ洢ʱ��ͨ�����������ʽ�ṹ����ʽ�洢��

//2.˳���
//˳�������һ�������ַ�����Ĵ洢��Ԫ���δ洢����Ԫ�ص����Խṹ��һ������²�������洢����������������ݵ���ɾ��ġ�
//˳���������飬����������Ļ����ϣ�����Ҫ�������������洢�ģ�������Ծ���		
//˳���һ����Է�Ϊ:��̬˳��� �� ��̬˳���
//��̬˳���: ʹ�ö�������洢Ԫ��
//��̬˳���: ʹ�ö�̬���ٵ�����洢
#include "SeqList.h"

void TestSeqList1()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	SeqListPrint(&sl);

	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}

void TestSeqList2()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 10);
	SeqListPushFront(&sl, 20);
	SeqListPushFront(&sl, 30);
	SeqListPushFront(&sl, 40);
	SeqListPushFront(&sl, 50);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListInsert(&sl, 2, 50);
	SeqListErase(&sl, 2);
	int ret = SeqListFind(&sl, 10);
	printf("%d\n", ret);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}


//дһ������ͨѶ¼�ò˵�
void menu()
{
	printf("******************************************\n");
	printf("******	  1.��ʼ��	    2.��ӡ      ******\n");
	printf("******	  3.β��	    4.βɾ      ******\n");
	printf("******	  5.ͷ��        6.ͷɾ      ******\n");
	printf("******    7.ָ������    8.����      ******\n");
	printf("******    9.ָ��ɾ��    0.�˳�      ******\n");
	printf("******************************************\n");
}

int main()
{
	//TestSeqList1();
	//TestSeqList2();
	SL sl;
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d",&input);
		switch (input)
		{
		case INIT:
			SeqListInit(&sl);
			break;
		case PRINT:
			SeqListPrint(&sl);
			break;
		case PUSHBACK:
		{
			int x = 0;
			printf("������Ҫβ�������:>");
			scanf("%d", &x);
			SeqListPushBack(&sl, x);
		}
			break;
		case POPBACK:
			SeqListPopBack(&sl);
			break;
		case PUSHFRONT:
		{
			int x = 0;
			printf("������Ҫͷ�������:>");
			scanf("%d", &x);
			SeqListPushFront(&sl, x);
		}
			break;
		case POPFRONT:
			SeqListPopFront(&sl);
			break;
		case FIND:
		{
			int x = 0;
			printf("������Ҫ���ҵ�����:>");
			scanf("%d", &x);
			SeqListFind(&sl, x);
		}
			break;
		case INSERT:
		{
			int x = 0;
			int pos = 0;
			printf("������Ҫ���������:>");
			scanf("%d", &x);
			printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			SeqListInsert(&sl, pos, x);
		}
			break;
		case ERASE:
		{
			int pos = 0;
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			SeqListErase(&sl, pos);
		}
			break;
		case EXIT:
			SeqListDestory(&sl);
			printf("�˳�����\n");
			break;
		default :
			printf("ѡ�����������!\n");
			break;
		}
	} while (input);
	return 0;
}