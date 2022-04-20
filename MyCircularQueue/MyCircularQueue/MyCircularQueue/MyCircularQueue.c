#define _CRT_SECURE_NO_WARNINGS 1

//������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������
//ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣
//����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��

//���ʵ��Ӧ��֧�����²�����
//	 MyCircularQueue(k) : �����������ö��г���Ϊ k ��
//	 Front : �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
//	 Rear : ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
//	 enQueue(value) : ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
//	 deQueue() : ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
//	 isEmpty() : ���ѭ�������Ƿ�Ϊ�ա�
//	 isFull() : ���ѭ�������Ƿ�������

//�����������黹������ʵ�֣���Ҫ�࿪һ���ռ䣬�����޷��пջ�������

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	int* a;
	int front;
	int tail;
	int k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->a = (int*)malloc(sizeof(int)*(k + 1));
	cq->front = cq->tail = 0;
	cq->k = k;
	return cq;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	obj->a[obj->tail] = value;
	++obj->tail;
	obj->tail %= (obj->k + 1);
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	++obj->front;
	obj->front %= (obj->k + 1);
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->a[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	if (obj->tail == 0)
	{
		return obj->a[obj->k];
	}
	else
	{
		return obj->a[obj->tail - 1];
	}
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->front == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return (obj->tail + 1) % (obj->k + 1) == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->a);
	free(obj);
}