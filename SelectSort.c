#include <stdio.h>
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//void SelectSort(int* a, int n)
//{
//	int begin = 0, end = n - 1;
//	while (begin < end)
//	{
//		int mini = begin, maxi = begin;
//		for (int i = begin + 1; i <= end; ++i)
//		{
//			if (a[i] > a[maxi])
//			{
//				maxi = i;
//			}
//			if (a[i] < a[mini])
//			{
//				mini = i;
//			}
//		}
//		Swap(&a[begin], &a[mini]);
//		//ÐÞÕýÒ»ÏÂmaxi
//		if (maxi == begin)
//		{
//			maxi = mini;
//		}
//		Swap(&a[end], &a[maxi]);
//		++begin;
//		--end;
//	}
//}
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;

	while (begin < end)
	{
		int maxi = begin, mini = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}