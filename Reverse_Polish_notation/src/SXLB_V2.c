#include "SXLB_V2.h"

List* List_create()
{
    List *create = calloc(1,sizeof(List));
    if (create == NULL)
    {
        goto error;
    }
    create->count = 0;
    create->first = NULL;
    create->last = NULL;
    return create;
    error:
    return NULL;
}

void List_destroy(List *list)
{
    if (list == NULL)
    {
       return; 
    }

    ListNode *mid;

    for (mid = list->first; mid != NULL; mid = mid->next)
    {
        if (mid->prev != NULL)
        {
            free(mid->prev);
        }
    }

    if (list->last != NULL)
    {
        free(list->last);
    }

        free(list);
    

    return;
}

void List_clear(List *list)
{
    if (list == NULL)
    {
       return; 
    }

    ListNode *mid;

    for (mid = list->first; mid != NULL; mid = mid->next)
    {
        if (mid->value != NULL)
        {
            free(mid->value);
        }
    }

    return;
}

void List_clear_destroy(List *list)
{
    List_clear(list);
    List_destroy(list);
    return;
}

void List_in_first(List *list, void *value)
{                                                          
    if (list == NULL)                                      
    {                                                      
       return; 
    }

    ListNode *node = calloc(1,sizeof(ListNode));
    if (node == NULL)
    {
        goto error;
    }
    node->value = value;

    if (list->count == 0 && list->first == NULL && list->last == NULL)
    {
        list->first = node;
        list->last = node;
    }
    else
    {
        list->first->prev = node;
        node->next = list->first;
        list->first = node;
    }

    list->count += 1;

    error:
    return;
}

void List_in_last(List *list, void *value)
{                                                          
    if (list == NULL)                                      
    {                                                      
       return; 
    }

    ListNode *node = calloc(1,sizeof(ListNode));
    if (node == NULL)
    {
        goto error;
    }
    node->value = value;

    if (list->count == 0 && list->first == NULL && list->last == NULL)
    {
        list->first = node;
        list->last = node;
    }
    else
    {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }

    list->count += 1;

    error:
    return;
}

void List_remove_first(List *list)
{
    if (list == NULL || list->count == 0)
    {
        goto error;
    }

    ListNode *mid;

    if (list->count == 1)
    {
        free(list->first);
        list->first = NULL;
        list->last = NULL;
    }
    else
    {
        mid = list->first->next;
        mid->prev = NULL;
        free(list->first);
        list->first = mid;
    }

    list->count -= 1;

    error:
    return;
}

void List_remove_last(List *list)
{
    if (list == NULL || list->count == 0)
    {
        goto error;
    }

    ListNode *mid;

    if (list->count == 1)
    {
        free(list->last);
        list->first = NULL;
        list->last = NULL;
    }
    else
    {
        mid = list->last->prev;
        mid->next = NULL;
        free(list->last);
        list->last = mid;
    }

    list->count -= 1;

    error:
    return;
}


void List_in_first_other(List *list, void *value, int num)//插入在 num 数前
{
    if (list == NULL || list->count == 0)                                      
    {                                                      
       return; 
    }

    ListNode *node = calloc(1,sizeof(ListNode));
    if (node == NULL)
    {
        goto error;
    }
    node->value = value;
    
    int i = 1;
    ListNode *mid;

    mid = list->first;

    if (num == 1)
    {
        List_in_first(list, value);
    }
    else if (num > list->count)
    {   
        List_in_last(list, value);
    }
    else
    {
        for (i = 0; i < num && mid != NULL; i++, mid = mid->next);
        node->next = mid;
        node->prev = mid->prev->next;
        mid->prev->next = node;
        mid->prev = node;
        list->count += 1;
    }

    error:
    return;
}