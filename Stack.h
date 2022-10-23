//#pragma once
//#include <stdio.h>
//#include <stdbool.h>
//#include <assert.h>
//#include <stdlib.h>
//
//typedef int SDataType;
//typedef struct StackNode
//{
//	SDataType* a;
//	int top;
//	int capacity;
//}ST;
//void StackInit(ST* ps);
//void StackPush(ST* ps,SDataType x);
//void StackPop(ST* ps);
//SDataType StackTop(ST* ps);
//void StackDestory(ST* ps);
//bool StackEmpty(ST* ps);
//int StackSize(ST* ps);
#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

typedef int SDataType;
typedef struct StackNode
{
	SDataType* a;
	int top;
	int capacity;
}ST;
void StackInit(ST* ps);//��ʼ��
void StackDestory(ST* ps);//����
void StackPush(ST* ps,SDataType x);//��ջ
void StackPop(ST* ps);//��ջ

SDataType StackTop(ST* ps);//ջ��Ԫ��
bool StackEmpty(ST* ps);//�п�
int StackSize(ST* ps);//����