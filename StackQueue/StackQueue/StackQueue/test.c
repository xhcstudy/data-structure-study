#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
//ջ:һ����������Ա���ֻ�����ڹ̶���һ�˽��в����ɾ��Ԫ�ز�����
//�������ݲ����ɾ��������һ�˳�Ϊջ������һ�˳�Ϊջ�ס�
//ջ�е�����Ԫ�����غ���ȳ�LIFO (Last ln First Out)��ԭ��
//ѹջ:ջ�Ĳ������������ջ / ѹջ / ��ջ����������ջ����
//��ջ : ջ��ɾ������������ջ��������Ҳ��ջ����

void TestStack()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	StackDestroy(&st);
}

int main()
{
	TestStack();
	return 0;
}
