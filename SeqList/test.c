#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1.线性表
//线性表(linear list)是n个具有相同特性的数据元素的有限序列。线性表是一种在实际中广泛使用的数据结构，常见的线性表:顺序表、链表、栈、队列、字符串...
//线性表在逻辑上是线性结构，也就说是连续的一条直线。但是在物理结构上并不一定是连续的，线性表在物理上存储时，通常以数组和链式结构的形式存储。

//2.顺序表
//顺序表是用一段物理地址连续的存储单元依次存储数据元素的线性结构，一般情况下采用数组存储。在数组上完成数据的增删查改。
//顺序表就是数组，但是在数组的基础上，它还要求数据是连续存储的，不能跳跃间隔		
//顺序表一般可以分为:静态顺序表 和 动态顺序表
//静态顺序表: 使用定长数组存储元素
//动态顺序表: 使用动态开辟的数组存储
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


//写一个类似通讯录得菜单
void menu()
{
	printf("******************************************\n");
	printf("******	  1.初始化	    2.打印      ******\n");
	printf("******	  3.尾插	    4.尾删      ******\n");
	printf("******	  5.头插        6.头删      ******\n");
	printf("******    7.指定插入    8.查找      ******\n");
	printf("******    9.指定删除    0.退出      ******\n");
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
		printf("请选择:>");
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
			printf("请输入要尾插的数据:>");
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
			printf("请输入要头插的数据:>");
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
			printf("请输入要查找的数据:>");
			scanf("%d", &x);
			SeqListFind(&sl, x);
		}
			break;
		case INSERT:
		{
			int x = 0;
			int pos = 0;
			printf("请输入要插入的数据:>");
			scanf("%d", &x);
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			SeqListInsert(&sl, pos, x);
		}
			break;
		case ERASE:
		{
			int pos = 0;
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			SeqListErase(&sl, pos);
		}
			break;
		case EXIT:
			SeqListDestory(&sl);
			printf("退出程序\n");
			break;
		default :
			printf("选择错误，请重试!\n");
			break;
		}
	} while (input);
	return 0;
}