#include "hextobin.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *val[] = {"00", "00", "00", "00", "12", "1D", "F0", "1D", "F0", "12", "00", "00", "76", "21", "2A", "1D", "2A", "1D", "21", "1D", "76", "00", "00","\0"};
    HtoBList *list = createHtoBList();
    if (list == NULL) {
        fprintf(stderr, "Failed to allocate memory for HtoBList\n");
        return EXIT_FAILURE;
    }
    int i = 0;
    while (i < sizeof(val) / sizeof(val[0]))
    {
        inHtoBList(list,val[i]);
        i++;
    }
    HextoBin(list);
    delHtoBList(list);
    return 0;
}