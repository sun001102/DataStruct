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
void StackInit(ST* ps);//初始化
void StackDestory(ST* ps);//销毁
void StackPush(ST* ps,SDataType x);//入栈
void StackPop(ST* ps);//出栈

SDataType StackTop(ST* ps);//栈顶元素
bool StackEmpty(ST* ps);//判空
int StackSize(ST* ps);//长度