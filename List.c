#include "List.h"
LTNode* ListInit()
{
	LTNode* guard = (LTNode*)malloc(sizeof(LTNode));
	if (guard == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	guard->next = guard;
	guard->prev = guard;
	return guard;
}

void ListPrint(LTNode* phead)
{
	assert(phead);
	printf("phead<=>");
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
LTNode* BuyListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	node->prev = NULL;
	node->next = NULL;
	node->data = x;
	return node;
}
void ListPushBack(LTNode* phead,LTDataType x)
{
	assert(phead);
	/*LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/
	ListInsert(phead, x);
}
void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	/*LTNode* newnode = BuyListNode(x);
	newnode->next = phead->next;
	phead->next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;*/
	ListInsert(phead->next, x);
}
bool ListEmpty(LTNode* phead)
{
	assert(phead);
	return phead->next == phead;
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));
	LTNode* tail = phead->prev;
	LTNode* prev = tail->prev;//ÕÒÎ²°Í
	prev->next = phead;
	phead->prev = prev;
	free(tail);
	tail = NULL;
}
void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));
	LTNode* first = phead->next;
	LTNode* second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);
	first = NULL;
}
size_t ListSize(LTNode* phead)
{
	assert(phead);
	size_t n = 0;
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		++n;
		cur = cur->next;
	}
	return n;
}
LTNode* ListFind(LTNode* phead,LTDataType x)
{
	assert(phead);
	size_t n = 0;
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}
void ListDestory(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	//phead=NULL;
}
