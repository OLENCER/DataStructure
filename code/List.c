/* 
    Name: list.c
    Date: 2022/8/22
    Author: OLENCER.
*/

#include "List.h"

void listCheckCapacity(struct List** list, char* function);
void listCheckEmpty(struct List** list, char* function);
void listCheckExist(struct List** list, char* function);
void listCheckIndex(struct List** list, ListIndex index, char* function);

void listInitialize(struct List** list)
{
    if(!(*list = (struct List*)malloc(sizeof(struct List))))
    {
        fprintf(stderr,"FAILURE: No enough space or power to initialize");
        exit(EXIT_FAILURE);
    }

    (*list)->length = 0;
}

void listDestroy(struct List** list)
{
    free(*list);
    *list = NULL;
}

bool listEmpty(struct List** list)
{
    listCheckExist(list, "listEmpty");

    if(!listLength(list))
    {
        return true;
    }

    return false;
}

ListLength listLength(struct List** list)
{
    listCheckExist(list, "listLength");

    return (*list)->length;
}

void listAdd(struct List** list, ListData listData)
{
    listCheckCapacity(list, "listAdd");

    (*list)->data[listLength(list)] = listData;
    (*list)->length++;
}

void listInsert(struct List** list, ListIndex index, ListData listData)
{
    listCheckCapacity(list, "listInsert");
    listCheckIndex(list, index, "listInsert");

    memmove((*list)->data + index + 1, (*list)->data + index,
            (listLength(list) - index) * sizeof(ListData));

    (*list)->data[index] = listData;
    (*list)->length++;
}

void listClear(struct List** list)
{
    listCheckExist(list, "listClear");

    (*list)->length = 0;
}

void listDelete(struct List** list)
{
    listCheckEmpty(list, "listDelete");

    (*list)->length--;
}

void listDrop(struct List** list, ListIndex index)
{
    listCheckEmpty(list, "listDrop");
    listCheckIndex(list, index, "listDrop");

    memmove((*list)->data + index, (*list)->data + index + 1,
            (listLength(list) - index) * sizeof(ListData));

    (*list)->length--;
}

void listReplace(struct List** list, ListIndex index, ListData listData)
{
    listCheckEmpty(list, "listReplace");
    listCheckIndex(list, index, "listReplace");

    (*list)->data[index] = listData;
}

ListData listGet(struct List** list, ListIndex index)
{
    listCheckEmpty(list, "listGet");
    listCheckIndex(list, index, "listGet");

    return (*list)->data[index];
}

ListReturnIndex listSearch(struct List** list, ListIndex from, ListData listData)
{
    listCheckEmpty(list, "listSearch");
    listCheckIndex(list, from, "listSearch");

    for(ListIndex index = from; index < listLength(list); index++)
    {
        if((*list)->data[index] == listData) { return index; }
    }
    return -1;
}

void listCheckCapacity(struct List** list, char* function)
{
    listCheckExist(list, function);

    if(listLength(list) == CAPACITY)
    {
        fprintf(stderr,"FAILURE: List reaches the maximum capacity when %s.", function);
        exit(EXIT_FAILURE);
    }
}

void listCheckEmpty(struct List** list, char* function)
{
    listCheckExist(list, function);

    if(listEmpty(list))
    {
        fprintf(stderr,"FAILURE: List is empty when %s.", function);
        exit(EXIT_FAILURE);
    }
}

void listCheckExist(struct List** list, char* function)
{
    if(!(*list))
    {
        fprintf(stderr,"FAILURE: List not exists when %s.", function);
        exit(EXIT_FAILURE);
    }
}

void listCheckIndex(struct List** list, ListIndex index, char* function)
{
    if(index >= listLength(list))
    {
        fprintf(stderr,"FAILURE: %s index exceeds the list length.", function);
        exit(EXIT_FAILURE);
    }
}