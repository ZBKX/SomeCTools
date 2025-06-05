#ifndef _hextobin_h_
#define _hextobin_h_

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct htoblist{
    char *list[MAX_SIZE]; 
    int index;
}HtoBList;

HtoBList *createHtoBList();

void delHtoBList(HtoBList *list);

void inHtoBList(HtoBList *list, char *val);

void returnHtoBcase(char *val);

void HextoBin(HtoBList *list);

#endif