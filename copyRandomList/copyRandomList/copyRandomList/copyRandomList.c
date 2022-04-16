#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//复制带随机指针的链表
//给你一个长度为n的链表，每个节点包含一个额外增加的随机指针random，该指针可以指向链表中的任何节点或空节点。
//构造这个链表的深拷贝。深拷贝应该正好由n个全新节点组成，其中每个新节点的值都设为其对应的原节点的值。
//新节点的next 指针和random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
//复制链表中的指针都不应指向原链表中的节点。
//例如，如果原链表中有X和Y两个节点，其中X.random-->Y。那么在复制链表中对应的两个节点x和y，同样有x.random-->y。
//返回复制链表的头节点。
//用一个由n个节点组成的链表来表示输入 / 输出中的链表。每个节点用一个[va1, random_index]表示:
//va1 : —个表示Node.val的整数。
//random_index : 随机指针指向的节点索引(范围从 0 到 n - 1 ); 如果不指向任何节点，则为nul1。
//你的代码只接受原链表的头节点head作为传入参数。

//思路:
//1.在原节点后面插入一个节点作为原节点的临时拷贝
//2.在拷贝节点上处理random问题 拷贝节点的random = 原节点random的下一个
//3.将拷贝节点剪下来重新链接成为一个新链表，该链表就是所需链表，并且将原链表恢复链接
struct Node 
{
	int val;
	struct Node *next;
	struct Node *random;
};

struct Node* copyRandomList(struct Node* head)
{
	struct Node* cur = head;
	//1.插入节点
	while (cur)
	{
		struct Node* next = cur->next;
		struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
		copy->val = cur->val;
		//插入
		cur->next = copy;
		copy->next = next;
		cur = next;
	}
	//2.利用拷贝节点处理random
	cur = head;
	while (cur)
	{
		struct Node* copy = cur->next;
		struct Node* next = copy->next;
		if (cur->random == NULL)
		{
			copy->random = NULL;
		}
		else
		{
			copy->random = cur->random->next;
		}
		cur = next;
	}
	//3.剪下拷贝节点然后将拷贝节点链接成新链表并且恢复原链表
	struct Node* newlisthead = NULL;
	struct Node* newlisttail = NULL;
	cur = head;
	while (cur)
	{
		struct Node* copy = cur->next;
		struct Node* next = copy->next;
		//链接新链表
		if (newlisthead == NULL)
		{
			newlisthead = copy;
			newlisttail = copy;
		}
		else
		{
			newlisttail->next = copy;
			newlisttail = copy;
		}
		//恢复原链表
		cur->next;
		cur = next;
	}
	return newlisthead;
}