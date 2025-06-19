#ifndef _STACK_V2_H_
#define _STACK_V2_H_

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "SXLB_V2.h"

typedef struct Stack
{
    struct List *list;
    int len;
}stack;

stack* Stack_create();

void Stack_destroy(stack *stack);

void Stack_input(stack *st, void *val);

void *Stack_output(stack *st);

#endif