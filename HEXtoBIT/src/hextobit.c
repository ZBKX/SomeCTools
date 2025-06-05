#include "hextobin.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

HtoBList *createHtoBList()
{
    HtoBList *list = (HtoBList*)malloc(sizeof(HtoBList));
    assert(list != NULL);

    int i;

    list->index = 0;

    for (i = 0; i < MAX_SIZE; i++)
    {
        list->list[i] = NULL;
    }

    return list;
}

void delHtoBList(HtoBList *list)
{
    if (list == NULL)
    {
        return;
    }
    int i;
    for(i = 0; i < list->index; i++)
    {
        free(list->list[i]);
    }
    free(list);
    return;
}

void inHtoBList(HtoBList *list, char *val)
{
    if (val == NULL || list == NULL) 
    {
        fprintf(stderr, "Error: NULL pointer passed to inHtoBList\n");
        return;
    }
    if (strnlen(val, 1) == 0)
    {
        fprintf(stderr, "Error: Empty string passed to inHtoBList\n");
        return;
    }
    char *str = (char *)malloc(strlen(val) + 1);
    assert(str != NULL);

    strcpy(str, val);
    list->list[list->index] = str;
    list->index++;
    return;
}

void returnHtoBcase(char *val)
{
    switch (*(val))
    {
    case '0':
        printf("0000");
        break;
    case '1': 
        printf("0001");
        break;
    case '2': 
        printf("0010");
        break;
    case '3': 
        printf("0011");
        break;
    case '4': 
        printf("0100");
        break;
    case '5': 
        printf("0101");
        break;
    case '6': 
        printf("0110");
        break;
    case '7': 
        printf("0111");
        break;
    case '8': 
        printf("1000");
        break;
    case '9': 
        printf("1001");
        break;
    case 'A': 
        printf("1010");
        break;
    case 'B': 
        printf("1011");
        break;
    case 'C': 
        printf("1100");
        break;
    case 'D': 
        printf("1101");
        break;
    case 'E': 
        printf("1110");
        break;
    case 'F': 
        printf("1111");
        break;
    case 'a': 
        printf("1010");
        break;
    case 'b': 
        printf("1011");
        break;
    case 'c': 
        printf("1100");
        break;
    case 'd': 
        printf("1101");
        break;
    case 'e': 
        printf("1110");
        break;
    case 'f': 
        printf("1111");
        break;                                                 
    default:
        break;
    }
}

void HextoBin(HtoBList *list)
{
    int i,j;
    char *obj;
    for (i = 0; i < list->index; i++)
    {
        obj = list->list[i];
        if (obj == NULL)
        {
            printf("NULL pointer encountered in HextoBin\n");
            continue;
        }
        //printf("%s:",obj);
        for (j = 0; *(obj + j) != '\0'; j++)
        {
            returnHtoBcase(obj + j);
        }
        printf("\n");
    }
    
    return;
}