#include <stdio.h>
#include <stdlib.h>
#include "hextobin.h"

In* HexToBinFindCreate()
{
    In *list = (In*)malloc(sizeof(In));
    for (list->index = 0; list->index < MAX_SIZE; list->index++)
    {
        list->seq[list->index] = '\0';
    }
    list->index = 0;
    return list;
}

void HexToBinFindDelete(In *in)
{
    if (in == NULL)
    {
        return;
    }
    free(in);
    return;
}

void HexToBinFind(char word)
{
    switch (word)
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
    }
    return;
}

void HexToBinData(In *list, char word)
{
    list->seq[list->index] = word;
    list->index++;
    return;
}

void HexToBinTran(In *list)
{
    int i;
    for (i = 0; i < list->index; i++)
    {
        HexToBinFind(list->seq[i]);
    }
    printf("\n");
    return;
}