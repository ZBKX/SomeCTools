#include <stdlib.h>
#include <stdio.h>
#include "graph_adjacency_matrix.h"
#include "struct.h"

GraphAdjMat *newGraphAdjMat()
{
    int i,j;
    GraphAdjMat *graph = (GraphAdjMat *)malloc(sizeof(GraphAdjMat));
    graph->size = 0;
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            graph->adjMat[i][j] = 0;
        }
    }
    return graph;
}

void delGraphAdjMat(GraphAdjMat *graph)
{
    free(graph);
}

void addVertex(GraphAdjMat *garph, int val)
{
    int i;
    if (garph->size == MAX_SIZE)
    {
        fprintf(stderr, "图的顶点数量已达最大值\n");
        return;
    }
    int n = garph->size;
    garph->vertices[n] = val;
    for (i = 0; i <= n; i++)
    {
        garph->adjMat[n][i] = garph->adjMat[i][n] = 0;
    }
    garph->size++;
}
//index为vertices索引，从0开始
void removeVertex(GraphAdjMat *graph, int index)
{ 
    int i,j;
    if (index < 0 || index >= graph->size)
    {
        fprintf(stderr, "顶点索引越界\n");
        return;
    }

    for (i = index; i < graph->size - 1; i++)
    {
        graph->vertices[i] = graph->vertices[i+1];
    }

    for (i = index; i < graph->size - 1; i++)
    {
        for (j = 0; j < graph->size; j++)
        {
            graph->adjMat[i][j] = graph->adjMat[i+1][j];
        }
    }

    for (i = 0; i < graph->size; i++)
    {
        for (j = index; j < graph->size - 1; j++)
        {
            graph->adjMat[i][j] = graph->adjMat[i][j+1];
        }
    }
    
    graph->size--;
}
//>-1表示存在，-1表示不存在.>-1情况是val的位置
int findVertex(GraphAdjMat *graph, int val)
{
    int i;
    int flag = -1;
    for (i = 0; i < graph->size; i++)
    {
        if (graph->vertices[i] == val)
        {
            flag = i;
            goto end;
        }
    }
    printf("没有找到%d值\n", val);
    end:
    return flag;
}
//i,j对应vertices元素索引
//调用 addEdge(graph, 0, 1)：将邻接矩阵 adjMat[0][1] 和 adjMat[1][0] 都设为 1，表示顶点 1 和顶点 2 之间添加了一条无向边。
void addEdge(GraphAdjMat *graph, int i, int j)
{
    if (i < 0 || j < 0 || i >= graph->size || j >= graph->size || i == j)
    {
        fprintf (stderr, "边索引越界或相等\n");
        return;
    }
    graph->adjMat[i][j] = 1;
    graph->adjMat[j][i] = 1;
}
//i,j对应vertices元素索引
void removeEdge(GraphAdjMat *graph, int i, int j)
{
    if (i < 0 || j < 0 || i >= graph->size || j >= graph->size || i == j)
    {
        fprintf (stderr, "边索引越界或相等\n");
        return;
    }
    graph->adjMat[i][j] = 0;
    graph->adjMat[j][i] = 0;
}

void printVertices(GraphAdjMat *graph)
{
    int i;
    for (i = 0; i < graph->size; i++)
    {
        printf("值%d的索引为%d \n",graph->vertices[i],i);
    }
}

void printGraphAdjMat(GraphAdjMat *graph)
{
    int i,j;
    printf("顶点列表 = ");
    for (i = 0; i <= graph->size - 1; i++)
    {
        printf("%d ",graph->vertices[i]);
    }
    printf("\n邻接矩阵 =\n");
    for (i = 0; i <= graph->size - 1; i++)
    {
        for (j = 0; j <= graph->size - 1; j++)
        {
            printf (" %d ,",graph->adjMat[j][i]);
        }
        printf("\n");
    }
}


