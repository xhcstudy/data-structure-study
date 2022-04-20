#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
STDataType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

void CheckCapacity(ST* ps)
{
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType*)*newcapacity);
		if (tmp == NULL)
		{
			printf("line:%d :realloc failed\n", __LINE__);
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	CheckCapacity(ps);
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

typedef struct
{
	ST pushST;
	ST popST;
} MyQueue;


MyQueue* myQueueCreate()
{
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->pushST);
	StackInit(&q->popST);
	return q;
}

void myQueuePush(MyQueue* obj, int x)
{
	StackPush(&obj->pushST, x);
}

int myQueuePop(MyQueue* obj)
{
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	int front = StackTop(&obj->popST);
	StackPop(&obj->popST);
	return front;
}

int myQueuePeek(MyQueue* obj)
{
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	int front = StackTop(&obj->popST);
	return front;
}

bool myQueueEmpty(MyQueue* obj)
{
	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj)
{
	StackDestroy(&obj->pushST);
	StackDestroy(&obj->popST);
	free(obj);
}
