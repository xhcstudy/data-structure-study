#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;	
}

void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListCheckCapacity(SL* ps)
{
	//没有数据时给四个数据空间   内存不够时扩容2倍
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (NULL == tmp)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqListPushBack(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);
	
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SL* ps)
{
	//温柔一点的处理方式
	//if (ps->size > 0)
	//{
	//	ps->size--;
	//}

	//暴力方式
	assert(ps->size > 0);
	ps->size--;
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);

	//挪动数据
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);

	//挪动数据

	//循环实现
	//int begin = 1;
	//while (begin < ps->size)
	//{
	//	ps->a[begin - 1] = ps->a[begin];
	//	begin++;
	//}

	//ps->size--;

	//字符串函数实现
	memmove(ps->a, ps->a + 1, (ps->size - 1)*sizeof(SLDataType));

	ps->size--;
}

int SeqListFind(SL* ps, SLDataType x)
{
	int i = 0;
	for (i = 0; i < ps->size - 1; i++)
	{
		if (x == ps->a[i])
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	SeqListCheckCapacity(ps);
	assert((pos < ps->size) && (pos >= 0));
	int i = 0;
	for (i = ps->size - 1; i >= pos; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SL* ps, int pos)
{
	assert((pos < ps->size) && (pos >= 0));
	int i = 0;
	for (i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
