#include "List.h"
void TestList1()
{
	LTNode* plist=ListInit();
	ListPushBack(plist, 3);
	ListPushBack(plist, 7);
	ListPushBack(plist, 7);

	ListPrint(plist);
	ListPushFront(plist, 0);
	ListPrint(plist);
}
void TestList2()
{
	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 8);
	ListPrint(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);
	ListPopBack(plist);
	ListPrint(plist);
	ListPopBack(plist);
	ListPrint(plist);
}
void TestList3()
{
	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 1);
	ListPushBack(plist, 8);

	ListPrint(plist);
	ListPushFront(plist, 0);
	ListPushFront(plist, 1);
	ListPrint(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);
	ListPopFront(plist);
	ListPrint(plist);
	ListPopFront(plist);
	ListPrint(plist); 
	
}
void TestList4()
{
	LTNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 8);

	ListPrint(plist);
	ListInsert(3, 60);
	ListPrint(plist);
}

	
int main()
	{
	TestList1();
	return 0;
}



