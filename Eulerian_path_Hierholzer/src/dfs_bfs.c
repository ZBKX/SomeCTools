#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "dfs_bfs.h"

DFSList *newDFSList(GraphAdjMat *graph)
{
    int i;
    DFSList *dfs = (DFSList*)malloc(sizeof(DFSList));
    if (!dfs)
    {
        fprintf(stderr, "未创建DFSList变量\n");
        return NULL;
    }
    for (i = 0; i < MAX_SIZE; i++)
    {
        dfs->visit[i] = 0;
    }
    dfs->size = graph->size;
    return dfs;
}

BFSList *newBFSList(GraphAdjMat *graph)
{
    int i;
    BFSList *bfs = (BFSList*)malloc(sizeof(BFSList) );
    if (!bfs)
    {
        fprintf(stderr, "未创建BFSList变量\n");
        return NULL;
    }
    for (i = 0; i < MAX_SIZE; i++)
    {
        bfs->visit[i] = 0;
        bfs->queue[i] = 0;
    }
    bfs->size = graph->size;
    bfs->end = 0;
    bfs->head = 0;
    return bfs;
}

void delDFSList(DFSList *list)
{
    free(list);
}

void delBFSList(BFSList *list)
{
    free(list);
}

void InQueue(BFSList *list,int num)
{
    list->queue[list->end] = num;
    list->end++;
}

int OutQueue(BFSList *list)
{
    int num;
    num = list->queue[list->head];
    list->head++;
    return num;
}
//1表示空
int isEmpty(BFSList *list)
{
    return (list->end == list->head);
}
//val为矩阵的纵坐标索引
void DFS(GraphAdjMat *graph, DFSList *list, int val)
{
    int i;
    /*访问操作*/
    printf("节点数值是：%d\n", graph->vertices[val]);
    /*访问操作*/
    list->visit[val] = 1;
    list->size++;
    for (i = 0; i < graph->size; i++)
    {
        if (graph->adjMat[val][i] == 1 && list->visit[i] == 0)
        {
            DFS(graph,list,i);
        }
    }
}
//val为矩阵的纵坐标索引
void BFS(GraphAdjMat *graph, BFSList *list, int val)
{
    int out;
    int i;
    /*访问操作*/
    printf("初始节点数值是：%d\n", graph->vertices[val]);
    /*访问操作*/
    list->visit[val] = 1;
    InQueue(list,val);
    while (isEmpty(list) == 0)
    {
        out = OutQueue(list);
        for (i = 0; i < graph->size; i++)
        {
            if (graph->adjMat[out][i] == 1 && list->visit[i] == 0)
            {
                    /*访问操作*/
                    printf("节点数值是：%d\n", graph->vertices[i]);
                    /*访问操作*/
                    list->visit[i] = 1;
                    InQueue(list, i);
            }
        }
    }   
}