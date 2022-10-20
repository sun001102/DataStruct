#include "Queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* del = cur;
		cur = cur->next;
		free(cur);
	}
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	
	QNode* newnode = (QNode*)malloc(sizeof(QNode));//���ٴ����ڵ�
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}//��ʼ��
	if (pq->tail== NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;//����
		pq->tail = newnode;//����β
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	if (pq->head->next== NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* del = pq->head;//��ʱ���
		pq->head = pq->head->next;//��ͷ(����)
		free(del);//ɾͷ
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
	return pq->head == NULL && pq->tail == NULL;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	int n = 0;
	while (cur)
	{
		++n;
		cur = cur->next;
	}
	return n;
}