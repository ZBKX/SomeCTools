#include "hierholzer.h"
#include "struct.h"
#include "dfs_bfs.h"
#include "graph_adjacency_matrix.h"
#include <stdlib.h>
#include <stdio.h>

HieList *newHieList(GraphAdjMat *graph)
{
    int i;
    int j;
    HieList *list = (HieList*)malloc(sizeof(HieList));
    if (!list)
    {
        fprintf(stderr,"HeiList未成功创建");
        return NULL;
    }
    list->evenindex = 0;
    list->oddindex = 0;
    list->top = -1;
    list->odd[0] = 0;
    list->odd[1] = 0;
    list->odd[2] = 0;
    list->size = graph->size;
    for (i = 0; i < MAX_SIZE; i++)
    {
        list->even[i] = 0;
        list->vertices[i] = graph->vertices[i];
        list->stack[i] = 0;
        for (j = 0; j < MAX_SIZE; j++)
        {
            list->adjMat[i][j] = graph->adjMat[i][j];
        } 
    }
    return list;
}

void CheckEulerianPath(HieList *list)
{
    int i,j;
    int ans;
    for (i = 0; i < list->size; i++)
    {
        ans = 0;
        if (list->oddindex == 3)
        {
            goto goout;
        }
        for (j = 0; j < list->size; j++)
        {
            ans += list->adjMat[i][j];
        }
        if (ans % 2 == 1)
        {
            list->odd[list->oddindex] = list->vertices[i];
            list->oddindex++;
        }
        else if (ans % 2 == 0)
        {
            list->even[list->evenindex] = list->vertices[i];
            list->evenindex++;
        }
    }
    if (list->oddindex == 1)
    {
        goto goout;
    }
    return;
    goout:
    fprintf(stderr,"此图不满足欧拉路径奇数节点数的条件");
    return;
}

//>-1表示存在，-1表示不存在.>-1情况是val的位置
int findHieVertex(HieList *list, int val)
{
    int i;
    int flag = -1;
    for (i = 0; i < list->size; i++)
    {
        if (list->vertices[i] == val)
        {
            flag = i;
            goto end;
        }
    }
    printf("没有找到%d值\n", val);
    end:
    return flag;
}
//输出索引值
int StratHieNode (HieList *list)
{
    int flag;
    if (list->oddindex != 0)
    {
        flag = findHieVertex(list,list->odd[0]);
    }
    else
    {
        flag = findHieVertex(list,list->even[0]);
    }
    return flag; 
}
//strat为矩阵纵索引
void Hieholzer(HieList *list, int strat)
{
    int i;
    for ( i = 0; i < list->size; i++)
    {
        if (list->adjMat[strat][i] == 1)
        {
            list->adjMat[strat][i] = 0;
            list->adjMat[i][strat] = 0;
            Hieholzer(list,i);
        }
    }
    list->stack[list->top + 1] = strat;
    list->top++;
    return;
}

void printHieholzer(HieList *list)
{
    int i = list->top;
    for (i; i > -1; i--)
    {
        printf("欧拉节点值：%d\n",list->vertices[(list->stack[i])]);
    }
    return;
}