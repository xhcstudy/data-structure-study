#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
//栈:一种特殊的线性表，其只允许在固定的一端进行插入和删除元素操作。
//进行数据插入和删除操作的一端称为栈顶，另一端称为栈底。
//栈中的数据元素遵守后进先出LIFO (Last ln First Out)的原则。
//压栈:栈的插入操作叫做进栈 / 压栈 / 入栈，入数据在栈顶。
//出栈 : 栈的删除操作叫做出栈。出数据也在栈顶。

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
