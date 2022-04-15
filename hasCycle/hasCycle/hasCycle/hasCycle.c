#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//环形链表

//给你一个链表的头节点head，判断链表中是否有环。
//如果链表中有某个节点，可以通过连续跟踪next指针再次到达，则链表中存在环。
//为了表示给定链表中的环，测评系统内部使用整数pos来表示链表尾连接到链表中的位置(索引从0开始)。
//注意:pos不作为参数进行传递。仅仅是为了标识链表的实际情况。如果链表中有环返回true，否则返回false。

//思路:快慢指针问题 使用一个slow 和 fast指针 slow走一步，fast走两步，如果不带环 fast会走到空，如果带环 fast会追上slow

struct ListNode 
{
	int val;
	struct ListNode *next;
};

//如果有环返回1，没环返回0
int hasCycle(struct ListNode *head) 
{
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			return 1;
		}
	}
	return 0;
}


//延伸问题:
//1、为什么slow和fast一定会在环中相遇 ? 会不会在环里面错过，永远遇不上 ? 请证明一下
//结论 : 他们一定会相遇，但是需要我们证明一下。
//2、为什么slow走一步，fast走的两步呢 ? 能不能fast走一次走n步(n > 2) ? 请证明一下
//结论 : fast一次走n步 , n > 2不一定会相遇
