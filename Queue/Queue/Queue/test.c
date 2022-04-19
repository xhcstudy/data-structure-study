#define _CRT_SECURE_NO_WARNINGS 1

//����:ֻ������һ�˽��в������ݲ���������һ�˽���ɾ�����ݲ������������Ա����о����Ƚ��ȳ�FIFO(First In First Out)
//����� : ���в��������һ�˳�Ϊ��β
//������ : ����ɾ��������һ�˳�Ϊ��ͷ
#include "Queue.h"

void TestQueue1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	
	QueueDestroy(&q);
}

int main()
{
	TestQueue1();
	return 0;
}
