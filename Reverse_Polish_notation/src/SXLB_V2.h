#ifndef _SXLB_V2_H_
#define _SXLB_V2_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef struct ListNode
{ 
    struct ListNode *next;
    struct ListNode *prev;
    void *value;
}ListNode;

typedef struct List
{
    int count;
    ListNode *first;
    ListNode *last;
}List;

struct List* List_create();

void List_destroy(List *list);

void List_clear(List *list);

void List_clear_destroy(List *list);

void List_in_first(List *list, void *value);

void List_in_last(List *list, void *value);

void List_remove_first(List *list);

void List_remove_last(List *list);

void List_in_first_other(List *list, void *value, int num);

#endif