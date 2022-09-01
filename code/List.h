#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <memory.h>
#include <stdbool.h>

#define CAPACITY UINT16_MAX

typedef int ListData;
typedef uint16_t ListIndex;
typedef uint16_t ListLength;
typedef int32_t ListReturnIndex;

struct List
{
    ListData data[CAPACITY];
    ListLength length;
};

void listInitialize(struct List** list);

void listDestroy(struct List** list);
bool listEmpty(struct List** list);
ListLength listLength(struct List** list);

void listAdd(struct List** list, ListData listData);
void listInsert(struct List** list, ListIndex index, ListData listData);

void listClear(struct List** list);
void listDelete(struct List** list);
void listDrop(struct List** list, ListIndex index);

void listReplace(struct List** list, ListIndex index, ListData listData);

ListData listGet(struct List** list, ListIndex index);
ListReturnIndex listSearch(struct List** list, ListIndex from, ListData listData);

#endif //_LIST_H_