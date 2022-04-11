#define _CRT_SECURE_NO_WARNINGS 1
#include "Singly Linked List.h"
//顺序表的缺陷:
//1.空间不够了需要增容，增容需要付出代价
//2.避免频繁扩容，我们满了基本都是扩2倍，可能就会导致一定的空间浪费
//3.顺序表要求数据从开始位置连续存储，那么我们在头部或者中间位置插入删除数据就需要挪动数据，效率不高
//优点:
//支持随机访问   -    有些算法需要结构支持随机访问，如:二分查找、优化的快排

//针对顺序表的缺陷，就设计出了链表
//链表
//优点
//按需申请空间，不用了就释放空间(更合理得使用了空间)
//头部中间插入数据，不需要挪动数据
//不存在空间浪费
//缺点:
//每存一个数据，都要存一个指针去链接后面得数据节点
//不支持随机访问(用下标访问第i个)

//单链表的缺陷还是很多的，单纯单链表增删查改的意义不大
//1.很多OJ题目考察的都是单链表
//2.单链表更多的是去更复杂数据结构的子结构

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
		printf("第%d个节点为:%p->%d\n", ++i, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}
	//修改
	pos = SListFind(plist, 3);
	if (pos)
	{
		pos->data = 30;
	}
	SListPrint(plist);
	//1前面插入一个30
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