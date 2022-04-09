#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#ifndef __SEQLIST_H__
#define __SEQLIST_H__

enum
{
	EXIT,
	INIT,
	PRINT,
	PUSHBACK,
	POPBACK,
	PUSHFRONT,
	POPFRONT,
	FIND,
	INSERT,
	ERASE
};

typedef int SLDataType;
//��̬���ݱ�
typedef struct SeqList
{
	SLDataType* a;
	int size;		//��ʾ�����д洢�˶��ٸ�����
	int capacity;	//����ʵ���ܴ����ݵĿռ������Ƕ���
}SL;

//�ӿں���
void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
void SeqListDestory(SL* ps);

void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
//...

//�ҵ��˷���xλ���±꣬û���ҵ�����-1
int SeqListFind(SL* ps, SLDataType x);
//ָ���±�λ�ò���
void SeqListInsert(SL* ps, int pos, SLDataType x);
//ɾ��posλ�õ�����
void SeqListErase(SL* ps, int pos);
#endif 