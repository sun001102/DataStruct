#pragma once//防止重命名
#include <stdio.h>
#include <stdlib.h>
//动态顺序表
//#define M 10
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType*  a;
	int  size;//有效数据个数
	int capacity;//存储空间的大小
}SeqList;
void SeqListInit(SeqList* psl);//初始化
void SeqListDestory(SeqList* psl);//销毁
void SeqListPushBack(SeqList* psl, SLDataType x);//尾插
void SeqListPushFront(SeqList* psl, SLDataType x);//头删
void SeqListpopBcak(SeqList* psl);//尾删

