#include "SeqList.h"

void SeqListInit(SeqList*  psl)
{
	assert(psl);
	psl->a = NULL;
	psl->capacity = psl->size= 0;
}
void SeqListDestory(SeqList* psl)
{
	assert(psl);
	free(psl->a);
	psl->a = NULL;
	psl->size = psl->capacity = 0;
}
void SLCheckCapaCity(SeqList* psl)
{
	if (psl->size == psl->capacity)
	{
		int newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType* tmp = (SLDataType*)relloc(psl->a, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("relloc fail");
			exit(-1);
		}
		psl->a = tmp;
		psl->capacity = newCapacity;
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	void SLCheckCapaCity(psl);

	////检查容量
	//if (psl->size == psl->capacity)
	//{
	//	int newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
	//	SLDataType* tmp = (SLDataType*)relloc(psl->a, newCapacity * sizeof(SLDataType));
	//	if (tmp == NULL)
	//	{
	//		perror("relloc fail");
	//		exit(-1);
	//	}
	//	psl->a = tmp;
	//	psl->capacity = newCapacity;
	//}
	psl->a[psl->size] = x;
	psl->size++;
}
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);
	void SLCheckCapaCity(psl);
	int end = psl->size - 1;
	while (end >= 0)
	{
		psl->a[end + 1] = psl->a[end];
		--end;
	}
	psl->a[0] = x;
	psl->size++;
}
void SeqListpopBcak(SeqList* psl)
{
	assert(psl);
	//检查的检查
	if (psl->size==0)
	{
		return;
	}
	psl->size--;
}



