#include "Heap.h"

void HeapPrint(HP* php)
{
	assert(php);
	for (int i = 0; i < php->size;++i)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}
void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}
void HeapDestory(HP* php)
{

}
void Swap(HDataType*p1, HDataType* p2)
{
	HDataType* tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void Adjustup(HP* php, int child)
{
	int parent = child - 1 / 2;
	//while(parent>=0)  因为父亲=0 进来一次 孩子=父亲=0  父亲计算后=0-1/2  =1 又上去一次 死循环  所以使用 孩子判断
	while (child>0)
	{
		if (php->a[child] < php->a[parent])
		{
			Swap(&php->a[child], &php->a[parent]);//交换两个值
			child = parent;//往上走迭代
			parent = child - 1 / 2;//找父亲
		}
		else
		{
			break;
		}
	}
}
void HeapPush(HP* php, HDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newCapaCity = php->capacity == 0 ? 4 : php->capacity * 2;
		HDataType* tmp = (HDataType*)realloc(php->a, newCapaCity*sizeof(HDataType));//开辟大小易错
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newCapaCity;
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a, php->size-1);//从哪个位置向上调整？
}
void AdjustDown(HP* php, int n, int parent)//数组大小
{
	int minChild = parent * 2 + 1;//默认小孩子是左孩子
	while (minChild<n)//？防止越界数组
	{
		if (php->a[minChild]<n && php->a[minChild + 1] > php->a[minChild])//找出小的那个孩子
		{//防止数组越界   
			minChild++;
		}//小孩子右孩子
		if (php->a[minChild] < php->a[parent])//目前小根堆  叛逆
		{
		Swap(&php->a[minChild], &php->a[parent]);//交换
		parent = minChild;
		minChild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	Swap(php->a[0], php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);//??
}
HDataType HeapTop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	return php->a[0];
}
bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;//大小为0
}