#include "SList.h"
void SListPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d ", cur->next);
		cur = cur->next;
	}
	printf("NULL\n");
}
SLNode* BuySLNode(SLTDataType x)
{
	SLNode* newnode =(SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perro("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void SListPushFront(SLNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLNode*newnode = BuySLNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
void SListPushBack(SLNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLNode* newnode = BuySLNode(x);
	SLNode* tail = *pphead;
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	//ÕÒÎ²
	else
	{
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
		newnode->next = NULL;
	}
}
void SListPopFront(SLNode** pphead)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		return;
	}
	SLNode* del = *pphead;
	*pphead=(*pphead)->next;
	free(del);
	del = NULL;
}
void SListPopBack(SLNode** pphead)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		return;
	}
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLNode* prev = NULL;
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
		tail = NULL;
	}
}
SLNode* SListFind(SLNode* pphead, SLTDataType x)
{
	SLNode* cur = pphead;
	while (cur != NULL)
	{
		if (cur->data != x)
		{
			cur = cur->next;
		}
		return cur;
	}
	return NULL;
}
void SListInsert(SLNode** pphead, SLNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);
	SLNode* newnode = BuySLNode(x);
	if (pos == *pphead)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SLNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
			assert(cur);
		}
		cur->next = newnode;
		newnode->next = pos;
	}
  }
void SListInsertAfter(SLNode* pos, SLTDataType x)
{
	assert(pos);
	SLNode* newnode = BuySLNode(x);
	newnode->next = pos->next;//×¢ÒâË³Ðò
	pos->next = newnode;
}
void SListErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(pos);
	if (*pphead == pos)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
			assert(prev);
		}
		prev->next = pos->next;
		free(pos);
	}
}
void SListEraseAfter(SLNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	else
	{
		SLNode* next = pos->next;
		pos->next = next->next;
		free(next);
	}
}
