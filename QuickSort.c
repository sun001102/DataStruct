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
int PartSort(int* a, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		while (left < right && a[left <= a[keyi]])
		{
			++left;
		}
		if (left < right)
			Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	return left;
}
void QuickSort(int* a, int begin, int end)
{
	int keyi = PartSort(a, begin, end);
	if (begin >= end)
	{
		return;
	}
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}
