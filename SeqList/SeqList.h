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
//动态数据表
typedef struct SeqList
{
	SLDataType* a;
	int size;		//表示数组中存储了多少个数据
	int capacity;	//数组实际能存数据的空间容量是多少
}SL;

//接口函数
void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
void SeqListDestory(SL* ps);

void SeqListCheckCapacity(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
//...

//找到了返回x位置下标，没有找到返回-1
int SeqListFind(SL* ps, SLDataType x);
//指定下标位置插入
void SeqListInsert(SL* ps, int pos, SLDataType x);
//删除pos位置得数据
void SeqListErase(SL* ps, int pos);
#endif 