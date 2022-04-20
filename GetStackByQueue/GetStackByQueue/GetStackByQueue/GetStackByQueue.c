#define _CRT_SECURE_NO_WARNINGS 1

//用队列实现栈
//请你仅用两个队列实现一个后入先出的栈，并支持普通栈的四种操作(push、top、pop和empty)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	struct QueueNode* head;
	struct QueueNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->data = x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int count = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		++count;
		cur = cur->next;
	}
	return count;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}

typedef struct
{
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate()
{
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&st->q1);
	QueueInit(&st->q2);
	return st;
}

void myStackPush(MyStack* obj, int x)
{
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj)
{
	Queue* emptyQ = &obj->q1;
	Queue* nonemptyQ = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		emptyQ = &obj->q2;
		nonemptyQ = &obj->q1;
	}
	//有数据的队列只要元素个数还大于一个，就把元素丢到空队列，然后将有数据的最后一个元素pop掉就是队尾数据
	while (QueueSize(nonemptyQ) > 1)
	{
		QueuePush(emptyQ, QueueFront(nonemptyQ));
		QueuePop(nonemptyQ);
	}
	int top = QueueFront(nonemptyQ);
	QueuePop(nonemptyQ);
	return top;
}

int myStackTop(MyStack* obj)
{
	if (!QueueEmpty(&(obj->q1)))
	{
		return QueueBack(&(obj->q1));
	}
	else
	{
		return QueueBack(&(obj->q2));
	}
}

bool myStackEmpty(MyStack* obj)
{
	return QueueEmpty(&(obj->q1)) && QueueEmpty(&(obj->q2));
}

void myStackFree(MyStack* obj)
{
	QueueDestroy(&(obj->q1));
	QueueDestroy(&(obj->q2));
	free(obj);
}