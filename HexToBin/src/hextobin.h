#ifndef _hextobin_h_
#define _hextobin_h_

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct {
    char seq[MAX_SIZE];
    int index;
}In;

In* HexToBinFindCreate();

void HexToBinFindDelete(In *in);

void HexToBinFind(char word);

void HexToBinData(In *list, char word);

void HexToBinTran(In *list);

#endif