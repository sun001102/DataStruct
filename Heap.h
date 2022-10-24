#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


typedef int HDataType;
typedef struct HeapNode
{
	HDataType* a;//����
	int size;//��С
	int capacity;//����
}HP;

void HeapPrint(HP* php);
void HeapInit(HP* php);
void HeapDestory(HP* php);
void HeapPush(HP* php, HDataType x);
void HeapPop(HP* php);
HDataType HeapTop(HP* php);
bool HeapEmpty(HP* php);

