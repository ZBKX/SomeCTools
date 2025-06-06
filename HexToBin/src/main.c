#include <stdio.h>
#include "hextobin.h"

void inputdata(In *list);

int main()
{
    In *list;
    list = HexToBinFindCreate();

    inputdata(list);

    HexToBinTran(list);

    HexToBinFindDelete(list);

    return 0;
}

void inputdata(In *list)
{
    int i = 0;
    char word;
    while (i < MAX_SIZE)
    {
        printf("请输入一个字母('/'表示终止退出):");
        scanf("%s",&word);
        if (word == '/')
        {
            goto OUT;
        }
        printf("\n正在写入\n");
        i++;
        HexToBinData(list, word);    
    }
    printf("到达存储上限，强制退出");
    OUT:
    return;
}
