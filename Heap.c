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
	//while(parent>=0)  ��Ϊ����=0 ����һ�� ����=����=0  ���׼����=0-1/2  =1 ����ȥһ�� ��ѭ��  ����ʹ�� �����ж�
	while (child>0)
	{
		if (php->a[child] < php->a[parent])
		{
			Swap(&php->a[child], &php->a[parent]);//��������ֵ
			child = parent;//�����ߵ���
			parent = child - 1 / 2;//�Ҹ���
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
		HDataType* tmp = (HDataType*)realloc(php->a, newCapaCity*sizeof(HDataType));//���ٴ�С�״�
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
	AdjustUp(php->a, php->size-1);//���ĸ�λ�����ϵ�����
}
void AdjustDown(HP* php, int n, int parent)//�����С
{
	int minChild = parent * 2 + 1;//Ĭ��С����������
	while (minChild<n)//����ֹԽ������
	{
		if (php->a[minChild]<n && php->a[minChild + 1] > php->a[minChild])//�ҳ�С���Ǹ�����
		{//��ֹ����Խ��   
			minChild++;
		}//С�����Һ���
		if (php->a[minChild] < php->a[parent])//ĿǰС����  ����
		{
		Swap(&php->a[minChild], &php->a[parent]);//����
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
	return php->size == 0;//��СΪ0
}