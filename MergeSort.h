#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//void _MergeSort(int* a, int begin, int end, int* tmp)
//{
//	int mid = (begin + end)/ 2;
//
//	_MergeSort(a, begin, mid, tmp);
//	_MergeSort(a, mid + 1, end, tmp);
//	//归并
//	int begin1 = begin, end1 = mid;
//	int begin2 = mid + 1, end2 = end;
//	int i = begin;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (a[begin1] <= a[begin2])
//		{
//			tmp[i++] = a[begin1++];
//		}
//		else
//		{
//			tmp[i++] = a[begin2++];
//		}
//	}
//	while (begin1 <= end1)
//	{
//		tmp[i++] = a[begin1++];
//	}
//	while (begin2 <= end2)
//	{
//		tmp[i++] = a[begin2++];
//	}
//	memcpy(a + begin, tmp + begin, (end - begin - 1) * sizeof(int));
//}
//void MergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (tmp == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//	_MergeSort(a, 0, n - 1, tmp);
//	free(tmp);
//	tmp = NULL;
//}
//void _MergeSort(int* a, int begin, int end, int* tmp)
//{
//	int mid = (begin + end) / 2;
//	_MergeSort(a, begin, mid, tmp);
//	_MergeSort(a, mid + 1, end, tmp);
//	//归并
//	int begin1 = begin, end1 = mid;
//	int begin2 = mid + 1, end2 = end;
//	int i = begin;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (a[begin1] <= a[begin2])
//		{
//			tmp[i++] = a[begin1++];
//		}
//		else
//		{
//			tmp[i++] = a[begin2++];
//		}
//	}
//	while (begin1 <= end1)
//	{
//		tmp[i++] = a[begin1++];
//	}
//	while (begin2 <= end2)
//	{
//		tmp[i++] = a[begin2++];
//	}
//	memcpy(a + begin, tmp + begin, (end - begin - 1) * sizeof(int));
//}
//void MergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	_MergeSort(a, 0, n - 1, tmp);
//}
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	int mid = (begin + end) / 2;
	//分割
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);
	int i = begin;
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <=a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	//拷贝回原数组
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}