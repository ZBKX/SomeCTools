#ifndef _REPOLISH_H_
#define _REPOLISH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STACK_V2.h"

#define LEN(a) sizeof(a)/sizeof(a[0])

void repolish(char *sen, int len_sen);

void Sdisplay(stack *st);

void Ldisplay(List *li);

int priority(char word);

#endif