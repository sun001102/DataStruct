#include <stdio.h>
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//void PartSort(int* a, int left,int right)
//{
//	int keyi = left;
//	while (left < right)
//	{
//		while (left < right && a[right] >= a[keyi])//R��С
//		{
//			--right;
//		}
//		while (left < right && a[left] <= a[keyi])
//		{
//			++left;
//		}
//		if (left < right)
//			Swap(&a[left], &a[right]);
//	}//�����˽���
//	Swap(&a[left], &a[keyi]);
//}
// 
//int  PartSort(int* a, int left, int right)
//{
//	int keyi = left;
//	while (left < right)
//	{//R��С
//		while (left < right && a[right] >= a[keyi])
//		{
//			--right;
//		}//L�Ҵ�
//		while (left < right && a[left] <= a[keyi])
//		{
//			++left;
//		}//����
//		if (left < right)
//			Swap(&a[left], &a[right]);
//	}//��������
//	Swap(&a[left], &a[right]);
//	return left;
//}
//void QuickSort(int* a, int begin, int end)
//{
//	int keyi = PartSort(a, begin, end);
//	if (begin >= end)
//	{
//		return;
//	}
//	QuickSort(a, begin, keyi - 1);
//	QuickSort(a, keyi + 1, end);
//}
//int  PartSort(int* a, int left, int right)
//{
//	int keyi = left;
//	while (left < right)
//	{
//		while (left < right && a[right] >= a[keyi])
//		{
//			--right;
//		}
//		while (left < right && a[left] <= a[keyi])
//		{
//			++left;
//		}
//		if (left < right)
//			Swap(&a[left], &a[right]);
//	}
//	Swap(&a[left], &a[keyi]);
//	return left;
//}
//void QuickSort(int* a, int begin, int end)
//{
//	int keyi = PartSort(a, begin, end);
//	if (begin >= end)
//	{
//		return;
//	}
//	QuickSort(a, begin, keyi - 1);
//	QuickSort(a, keyi + 1, end);
//}
//int PartSort(int* a, int left, int right)
//{
//	int keyi = left;
//	while (left < right)
//	{
//		while (left < right && a[right] >= a[keyi])
//		{
//			--right;
//		}
//		while (left < right && a[left <= a[keyi]])
//		{
//			++left;
//		}
//		if (left < right)
//			Swap(&a[left], &a[right]);
//	}
//	Swap(&a[left], &a[keyi]);
//	return left;
//}
//void QuickSort(int* a, int begin, int end)
//{
//	int keyi = PartSort(a, begin, end);
//	if (begin >= end)
//	{
//		return;
//	}
//	QuickSort(a, begin, keyi - 1);
//	QuickSort(a, keyi + 1, end);
//}
//1.Hoare
//int PartSort(int* a,int left,int right)
//{
//	int keyi = left;
//	while (left < right)
//	{//R��С
//		while (left < right && a[right] >= a[keyi])
//		{
//			--right;
//		}
//		while (left < right && a[left] <= a[keyi])
//		{
//			++left;
//		}
//		if(left<right)
//		Swap(&a[left], &a[right]);
//	}//����
//	Swap(&a[left], &a[keyi]);
//	return left;
//}
int PartSort(int* a, int left, int right)
{
	int key = a[left];
	int hole = left;
	while (left < right)
	{//�ұ��Ҵ����߿�
		while (left < right && a[right] >=a[key])
		{
			--right;
		}
		a[hole] = a[right];
		hole = right;
		//�����С ��ұ߿�
		while (left < right && a[left] <= a[key])
		{
			++left;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}
//ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{//cur������keyС��ֵ ��ͣ���� ++prev,����prev��cur ��prev=cur ���ؽ���
 		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
			++cur;
		}
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}
//����ȡ���Ż�
int GetMidIndex(int* a, int left, int right)
{
	int mid = (right + left) / 2;//�м�ֵ
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else//a[left]>=a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
void QuickSort(int* a, int begin,int end)
{
	int keyi = PartSort(a, begin, end);
	if (begin >= end)
	{
		return;
	}
	PartSort(a, begin, keyi - 1);
	PartSort(a, keyi + 1, end);
}
//
//int PartSort(int* a, int begin, int end)
//{
//	int keyi = left;
//	int prev = left;
//	int cur = left + 1;
//	while (cur <= right)
//	{
//		if (a[cur] < a[keyi] && ++prev != cur)
//			Swap(&a[cur], &a[prev]);
//		++cur;
//	}
//	Swap(&a[keyi], &a[prev]);
//	return prev;
//}
int PartSort(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[left], &a[mid]);//����ȡ���Ż�
	int keyi = a[left];
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
			++cur;
		}
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}