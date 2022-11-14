#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)
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

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int  PartSort(int* a, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}
		while (left < right && a[left] <= a[keyi])
		{
			--left;
		}
		if (left < right)
			Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[keyi]);
	return left;
}
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	int keyi = PartSort(a, begin, end);
	//[begin, keyi-1] keyi [keyi+1, end]

	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}
