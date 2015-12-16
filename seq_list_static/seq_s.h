#pragma once

#define MAX 100
typedef int DataType;


#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct SeqList
{
	DataType data[MAX];
	int size;
}SeqList, *pSeqList;


void InitSeqlist(pSeqList plist);
void PrintSeqlist(pSeqList plist);

void PushBack(pSeqList plist, DataType x);
void PopBack(pSeqList plist);

void PushFront(pSeqList plist, DataType x);
void PopFront(pSeqList plist);

void Insert(pSeqList plist, int pos, DataType x);
void Remove(pSeqList plist, DataType x);
void RemoveAll(pSeqList plist, DataType x);

int Find(pSeqList plist, DataType x);

void ReverseList(pSeqList plist);
void SortList(pSeqList plist);



void InitSeqlist(pSeqList plist)
{
	assert(plist);
	//初始化内存块
	memset(plist->data, 0, MAX*sizeof(DataType));
	plist->size = 0;
}

void PrintSeqlist(pSeqList plist)
{
	assert(plist);
	int i = 0;
	for (i = 0; i < plist->size; ++i)
	{
		printf("%d ", plist->data[i]);
	}
	printf("\n");
}

void PushBack(pSeqList plist, DataType x)
{
	assert(plist);

	if (plist->size >= MAX)
	{
		printf("plist is full\n");
		return;
	}

	plist->data[plist->size++] = x;
}


void PopBack(pSeqList plist)
{
	assert(plist);

	if (plist->size == 0)
	{
		printf("list is empty\n");
		return;
	}
	//plist->data[--(plist->size)] = 0;
	--(plist->size);
}

void PushFront(pSeqList plist, DataType x)
{
	assert(plist);
	int end = plist->size;

	if (plist->size >= MAX)
	{
		printf("list is full\n");
		return;
	}
	for (; end > 0; end--)
	{
		plist->data[end] = plist->data[end - 1];
	}
	plist->data[0] = x;
	plist->size++;
}

void PopFront(pSeqList plist)
{
	assert(plist);
	int start = 0;
	
	if (plist->size == 0)
	{
		printf("list is empty\n");
		return;
	}
	for (; start < plist->size; start++)
	{
		plist->data[start] = plist->data[start + 1];
	}
	plist->size--;
}
void Insert(pSeqList plist, int pos, DataType x)
{
	int start = plist->size;
	assert(plist);

	if (plist->size >= MAX)
	{
		printf("list is full\n");
		return;
	}
	for (; start > pos; start--)
	{
		plist->data[start] = plist->data[start - 1];
	}
	plist->data[pos] = x;
	plist->size++;
}
void Remove(pSeqList plist, DataType x)
{
	assert(plist);
	int find = 0;
	int del = 0;
	if (plist->size == 0)
	{
		return;
	}
	//查找
	for (find = 0; find < plist->size; find++)
	{
		if (plist->data[find] == x)
		{
			del = find;
			break;
		}
	}
	//删除
	for (; del < plist->size-1; del++)
	{
		plist->data[del] = plist->data[del+1];
	}
	plist->size--;
}

void RemoveAll(pSeqList plist, DataType x)
{
	assert(plist);
	int IsFind = 0;
	IsFind = Find(plist, x);
	while (IsFind != -1)
	{
		Remove(plist, x);
		IsFind = Find(plist, x);
	}
}
int Find(pSeqList plist, DataType x)
{
	assert(plist);
	int find = 0;
	int del = 0;
	if (plist->size == 0)
	{
		return -1;
	}
	//查找
	for (find = 0; find < plist->size; find++)
	{
		if (plist->data[find] == x)
		{
			return find;
		}
	}
	return -1;
}

void ReverseList(pSeqList plist)
{
	assert(plist);
	int left = 0;
	int right = plist->size - 1;
	while (left < right)
	{
		DataType tmp = plist->data[left];
		plist->data[left] = plist->data[right];
		plist->data[right] = tmp;
		left++;
		right--;
	}
}

void SortList(pSeqList plist)
{
	assert(plist);

	int times = 0;
	for (; times < plist->size - 1; times++)
	{
		int index = 0;
		for (index = 0; index < plist->size - 1 - times; index++)
		{
			if (plist->data[index] > plist->data[index+1])
			{
				DataType tmp = plist->data[index];
				plist->data[index] = plist->data[index + 1];
				plist->data[index + 1] = tmp;
			}
		}
	}
}

