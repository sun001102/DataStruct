#include "Stack.h"
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	int newCapacity = ps->capacity == 0 ?4:newCapacity * 2;
	STDataType* tmp = (STDataType*)realloc(ps->a, newCapacity * (sizeof(STDataType)));
	if (tmp == NULL)
	{
		perror("realloc fail");
		exit(-1);
	}
	ps->a = tmp;
	ps->capacity = newCapacity;
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	--ps->top;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}
size_t StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}