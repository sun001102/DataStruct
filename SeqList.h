#pragma once//��ֹ������
#include <stdio.h>
#include <stdlib.h>
//��̬˳���
//#define M 10
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType*  a;
	int  size;//��Ч���ݸ���
	int capacity;//�洢�ռ�Ĵ�С
}SeqList;
void SeqListInit(SeqList* psl);//��ʼ��
void SeqListDestory(SeqList* psl);//����
void SeqListPushBack(SeqList* psl, SLDataType x);//β��
void SeqListPushFront(SeqList* psl, SLDataType x);//ͷɾ
void SeqListpopBcak(SeqList* psl);//βɾ

