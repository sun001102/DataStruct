#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;//’ª∂•Œª÷√
	int capacity;// »›¡ø
}ST;

void StackInit(ST* ps);
void StackDestory(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
STDataType StackTop(ST* ps);
bool StackEmpty(ST* ps);
size_t StackSize(ST* ps);