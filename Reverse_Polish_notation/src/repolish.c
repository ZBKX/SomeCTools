#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STACK_V2.h"
#include "repolish.h"

void repolish( char *sen, int len_sen)
{
    int i;
    stack *st;// + - * / ( )
    List *li;// 0-9 || End 
    st = Stack_create();
    li = List_create();
    ListNode *node1;
    void *mid1;
    for (i = 0; i < len_sen; i++)
    {
        if (*(sen + i) == ' ')
        {
            continue;
        }
        else if (*(sen + i) >= '0' && *(sen + i) <= '9')
        {
            List_in_last(li, sen + i);
            continue;
        }
        else if (*(sen + i) == '*' || *(sen + i) == '/' || *(sen + i) == '+' || *(sen + i) == '-')
        {
            while (st->len > 0 && priority(*(char*)(st->list->last->value)) >= priority(*(sen + i)))
            {
                mid1 = Stack_output(st);
                List_in_last(li, mid1);
            }
            Stack_input(st, sen + i);
            continue;
        }
        else if (*(sen + i) == '(')
        {
            Stack_input(st, sen + i);
            continue;
        }
        else if (*(sen + i) == ')')
        {
            mid1 = Stack_output(st);
            while(*(char*)(mid1) != '(' && st->len >= 0)
            {
                List_in_last(li, mid1);
                mid1 = Stack_output(st);
            }
            continue;             
        }
    }
    Sdisplay(st);
    Ldisplay(li);
    for (i = 0; i <= st->len; i++)
    {
        mid1 = Stack_output(st);
        List_in_last(li, mid1); 
    }
    Sdisplay(st);
    Ldisplay(li);    
    for (node1 = li->first; node1 != NULL; node1 = node1->next)
    {
        printf("%c", *(char*)(node1->value));
    }
    printf("\n");

    Stack_destroy(st);
    List_destroy(li);        
    return;
}

int priority(char word)
{
    int flag;
    switch (word)
    {
        case '/':
        case '*':
            flag = 2;
            break;        
        case '-':
        case '+':
            flag = 1;
            break;       
        default:
            flag = 0;
            break;
    }
    return flag;
}

void Sdisplay(stack *st)
{
    ListNode *node1;
    printf("The result is: ");
    for (node1 = st->list->first; node1 != NULL; node1 = node1->next)
    {
        printf("%c", *(char*)(node1->value));
    }
    printf("\n");
}

void Ldisplay(List *li)
{
    ListNode *node1;
    printf("The result is: ");
    for (node1 = li->first; node1 != NULL; node1 = node1->next)
    {
        printf("%c", *(char*)(node1->value));
    }
    printf("\n");
}