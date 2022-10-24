//#include "Queue.h"
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//	pq->head = pq->tail = NULL;
//}
//void QueueDestory(Queue* pq)
//{
//	assert(pq);
//	QNode* cur = pq->head;
//	while (cur)
//	{
//		QNode* del = cur;
//		cur = cur->next;
//		free(cur);
//	}
//}
//void QueuePush(Queue* pq, QDataType x)
//{
//	assert(pq);
//	
//	QNode* newnode = (QNode*)malloc(sizeof(QNode));//开辟创建节点
//	if (newnode == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	else
//	{
//		newnode->data = x;
//		newnode->next = NULL;
//	}//初始化
//	if (pq->tail== NULL)
//	{
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		pq->tail->next = newnode;//插入
//		pq->tail = newnode;//更新尾
//	}
//}
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	if (pq->head->next== NULL)
//	{
//		free(pq->head);
//		pq->head = pq->tail = NULL;
//	}
//	else
//	{
//		QNode* del = pq->head;//零时结点
//		pq->head = pq->head->next;//换头(保护)
//		free(del);//删头
//		del = NULL;
//	}
//}
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->head->data;
//}
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->tail->data;
//}
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//	return pq->head == NULL && pq->tail == NULL;
//}
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//	QNode* cur = pq->head;
//	int n = 0;
//	while (cur)
//	{
//		++n;
//		cur = cur->next;
//	}
//	return n;
//}
#include "Queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;//临时结点
	while (cur)
	{
		QNode* del = cur->next;
		free(del);
		del = NULL;
	}
	pq->head = pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));//开辟新结点
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* del = pq->head;
		pq->head = pq->head->next;
		free(del);
		del = NULL;
	}
}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QNode* cur = pq->head;
	int n = 0;
	while (cur)
	{
		++n;
		cur = cur->next;
	}
	return n;
}