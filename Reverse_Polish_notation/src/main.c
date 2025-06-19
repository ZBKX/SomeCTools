#include <stdio.h>
#include "STACK_V2.h"
#include "repolish.h"


int main(int argc, char *argv[])
{
    char sen1[1024] = "1 + ( 2 - 3 * 4 ) / 5 + 6";
    char sen2[1024] = "1+2-3";
    char sen3[1024] = "5+(1+2)*4-3";
    char sen4[1024] = "5+(1+2)*(4-3)";
    int len = 0;
    char in;
    /*printf("Please input the expression (end with '.'): ");
    scanf("%c", &in);
    while (in != '.')
    {
        sen[len] = in;
        len++;
        printf("\n");
        printf("Please input the expression (end with '.'): ");
        scanf("%c", &in);
    }
    */
    repolish(sen1, LEN(sen1));
    repolish(sen2, LEN(sen2));
    repolish(sen3, LEN(sen3));
    repolish(sen4, LEN(sen4));
    return 0;
}