#include "SXLB_V2.h"
#include "STACK_V2.h"

stack* Stack_create()
{
    stack *st = calloc(1, sizeof(stack));
    if (st == NULL)
    {
        goto error;
    }
    st->list = List_create();
    if (st->list == NULL)
    {
        free(st);
        goto error;
    }
    st->len = 0;
    return st;
    error:
    return NULL;
}

void Stack_destroy(stack *stack)
{
    if (stack == NULL)
    {
        return;
    }

    List_destroy(stack->list);
    
    free(stack);
    return;
}

void Stack_input(stack *st, void *val)
{
    if (st == NULL || val == NULL)
    {
        return;
    }

    List_in_last(st->list, val);
    st->len += 1;

    return;
}

void *Stack_output(stack *st)
{
    if (st == NULL || st->len == 0)
    {
        return NULL;
    }
    void *out;
    out = st->list->last->value; 

    List_remove_last(st->list);
    st->len -= 1;

    return out;
}