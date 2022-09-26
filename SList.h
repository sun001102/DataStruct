#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLNode;
void SListPrint(SLNode* phead);
SLNode* BuySLNode(SLTDataType x);
void SListPushFront(SLNode** pphead,SLTDataType x);
void SListPushBack(SLNode** pphead, SLTDataType x);
void SListPopFront(SLNode** pphead);
void SListPopBack(SLNode** pphead);
SLNode* SListFind(SLNode* pphead, SLTDataType x);
void SListInsert(SLNode** pphead, SLNode* pos, SLTDataType x);
void SListInsertAfter(SLNode* pos, SLTDataType x);
