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
//		while (left < right && a[right] >= a[keyi])//R找小
//		{
//			--right;
//		}
//		while (left < right && a[left] <= a[keyi])
//		{
//			++left;
//		}
//		if (left < right)
//			Swap(&a[left], &a[right]);
//	}//相遇了交换
//	Swap(&a[left], &a[keyi]);
//}
// 
//int  PartSort(int* a, int left, int right)
//{
//	int keyi = left;
//	while (left < right)
//	{//R找小
//		while (left < right && a[right] >= a[keyi])
//		{
//			--right;
//		}//L找大
//		while (left < right && a[left] <= a[keyi])
//		{
//			++left;
//		}//交换
//		if (left < right)
//			Swap(&a[left], &a[right]);
//	}//相遇交换
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
//	{//R找小
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
//	}//相遇
//	Swap(&a[left], &a[keyi]);
//	return left;
//}
int PartSort(int* a, int left, int right)
{
	int key = a[left];
	int hole = left;
	while (left < right)
	{//右边找大，填到左边坑
		while (left < right && a[right] >=a[key])
		{
			--right;
		}
		a[hole] = a[right];
		hole = right;
		//左边找小 填到右边坑
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
//	int mid = GetMidIndex(a, left, right);
//	Swap(&a[left], &a[right]);
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