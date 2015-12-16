#define _CRT_SECURE_NO_WARNINGS 1


#include "seq_s.h"

//InitSeqlist PushBack PopBack PrintSeqlist
void test1()
{
	SeqList slist;
	InitSeqlist(&slist);
	PushBack(&slist, 1);
	PushBack(&slist, 2);
	PushBack(&slist, 3);
	PushBack(&slist, 4);
	PrintSeqlist(&slist);

	PopBack(&slist);
	PopBack(&slist);
	PopBack(&slist);
	PopBack(&slist);
	PopBack(&slist);
	PopBack(&slist);
	
	PrintSeqlist(&slist);
}


void test2()
{
	SeqList slist;
	InitSeqlist(&slist);
	PushFront(&slist, 1);
	PushFront(&slist, 2);
	PushFront(&slist, 6);
	PushFront(&slist, 3);
	PushFront(&slist, 8);
	PushFront(&slist, 3);

	PushFront(&slist, 4);
	Insert(&slist, 2, 5);
	//Remove(&slist, 3);
	PrintSeqlist(&slist);
	ReverseList(&slist);
	PrintSeqlist(&slist);
	SortList(&slist);
	PrintSeqlist(&slist);

	RemoveAll(&slist, 3);
	PrintSeqlist(&slist);

	PopFront(&slist);
	PopFront(&slist);
	PopFront(&slist);
	PopFront(&slist);
	PopFront(&slist);
	PopFront(&slist);
	PopFront(&slist);
	PrintSeqlist(&slist);
}

int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}