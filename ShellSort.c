#include <stdio.h>
#include <stdlib.h>
//void ShellSort(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	gap = gap / 2;
//	for (int j = 0; j < gap; ++j) 
//	{
//		for (int i = j; i < n - gap; i += gap)
//		{
//			int end = 0;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (a[end] > tmp)
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//				a[end + gap] = tmp;
//			}
//		}
//}
//void ShellSort(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)
//		gap = gap / 2;
//	for (int j = 0; j <  gap; ++j)
//	{
//		for (int i = j; i < n - gap; ++i)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (a[end] > tmp)
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}
//}
//void ShellSort(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 2;
//		for (int j = 0; j < gap; ++j)
//		{
//			for (int i = j; i < n - gap; i += gap)
//			{
//				int end = i;
//				int tmp = a[end + gap];
//				while (end >= 0)
//				{
//					if (a[end] > tmp)
//					{
//						a[end + gap] = a[end];
//						end -= gap;
//					}
//					else
//					{
//						break;
//					}
//				}
//				a[end + gap] = tmp;
//			}
//		}
//	}
//}
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2;
		//gap=gap/3+1;
		for (int j = 0; j < gap; ++j)//Ô¤ÅÅĞò
		{
			for (int i = j; i < n - gap; i += gap)
			{
				int end = 0;
				int tmp = a[end + gap];
				while (end >= 0)
				{
					if (a[end] > tmp)
					{
						a[end + gap] = a[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				a[end + gap] = tmp;
			}
		}
	}
}