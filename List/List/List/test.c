#define _CRT_SECURE_NO_WARNINGS 1
//˫���ͷѭ������

#include "List.h"

void test1()
{
	ListNode* plist = NULL;
	ListInit(&plist);
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);

	ListNode* pos = ListFind(plist, 2);
	if (pos)
	{
		ListErase(pos);
	}
	ListPrint(plist);
	ListDestroy(plist);
	plist = NULL;
}

int main()
{
	test1();
	return 0;
}