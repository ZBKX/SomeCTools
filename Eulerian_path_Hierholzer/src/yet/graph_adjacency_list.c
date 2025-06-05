#include <stdlib.h>
#include <stdio.h>
#include "graph_adjacency_list.h"

AdjListNode *findNode(GraphAdjList *graph, Vertex *vet)
{
    int i;
    for (i = 0; i < graph->size; i++)
    {
        if (graph->heads[i] != NULL && graph->heads[i]->vertex == vet)
        {
            return graph->heads[i]; 
        }
    }
    return NULL;
}

void addEdgeHelper(AdjListNode *head, Vertex *vet)
{
    AdjListNode *node = (AdjListNode*)malloc(sizeof(AdjListNode));
    if (!node)
    {
        return;
    }
    node->vertex = vet;
    node->next = head->next;
    head->next = node;
}

void removeEdgeHelper(AdjListNode *head, Vertex *vet)
{
    AdjListNode *pre = head;
    AdjListNode *cur = head->next;
    if (!cur)
    {
        return;
    }
    while(cur != NULL && cur->vertex != vet)
    {
        pre = cur;
        cur = cur->next;
    }
    if (cur == NULL)
    {
        return;
    }
    pre->next = cur->next;
    free(cur);
}

GraphAdjList *newGraphAdjList()
{
    int i;
    GraphAdjList *graph = (GraphAdjList*)malloc(sizeof(GraphAdjList));
    if(!graph)
    {
        return NULL;
    }
    graph->size = 0;
    for (i = 0; i < MAX_SIZE; i++)
    {
        graph->heads[i] = NULL;
    }
    return graph;
}

VertexList *newVertexList()
{
    int i;
    VertexList *list = (VertexList*)malloc(sizeof(VertexList));
    if (!list)
    {
        return NULL;
    }
    list->size = 0;
    for (i = 0; i < MAX_SIZE; i++)
    {
        list->list[i] = NULL;
    }
    return list;
}

Vertex *newVertex(int val)
{
    Vertex *vet = (Vertex*)malloc(sizeof(Vertex));
    if (!vet)
    {
        return NULL;
    }
    vet->val = val;
    return vet;
}

void addVertexList(VertexList *list, Vertex *vet)
{   
    list->list[list->size] = vet;
    list->size++;
}

Vertex *findVertex(VertexList *list, int val)
{
    int i = 0;
    Vertex *node;
    Vertex *res = NULL;
    while(i < list->size)
    {
        node = list->list[i];
        if (node->val == val)
        {
            res = node;
            break;
        }
        i++;
    }
    if (res == NULL)
    {
        printf("未找到%d值,请更改数据", val);
        return NULL;
    }
    return res;
}

void delVertex(VertexList *list,int val)
{
    int i,j;
    Vertex *find = findVertex(list,val);
    if (!find)
    {
        return;
    }
    Vertex *node;
    for(i = 0; i < list->size; i++)
    {
        node = list->list[i];
        if (node->val == find->val)
        {
            free(node);
            break;
        }
    }
    for (j = i; j < list->size - 1; j++)
    {
        list->list[j] = list->list[j+1];
    }
    list->size--;
}

void delGraphAdjList(GraphAdjList *graph)
{
    AdjListNode *cur;
    AdjListNode *next;
    for(int i = 0; i < graph->size; i++)
    {
        cur = graph->heads[i];
        while(cur != NULL)
        {
            next = cur->next;
            if (cur != graph->heads[i])
            {
                //free(cur->vertex);
                free(cur);
            }
            cur = next;
        }
        free(graph->heads[i]->vertex);
        free(graph->heads[i]);
    }
    free(graph);
}

void addEdge(GraphAdjList *graph, Vertex *vet1, Vertex *vet2)
{
    AdjListNode *head1 = findNode(graph, vet1);
    AdjListNode *head2 = findNode(graph, vet2);
    assert(head1 != NULL && head2 != NULL && head1 != head2);
    addEdgeHelper(head1,vet2);
    addEdgeHelper(head2,vet1);
}

void removeEdge(GraphAdjList *graph, Vertex *vet1, Vertex *vet2)
{
    if (vet1 == vet2)
    {
        return;
    }
    AdjListNode *head1 = findNode(graph, vet1);
    AdjListNode *head2 = findNode(graph, vet2);
    assert(head1 != NULL && head2 != NULL);
    removeEdgeHelper(head1, head2->vertex);
    removeEdgeHelper(head2, head1->vertex);
}

void addVertex(GraphAdjList *graph, Vertex *vet)
{
    assert(graph != NULL && graph->size < MAX_SIZE && vet != NULL);
    AdjListNode * head = (AdjListNode*)malloc(sizeof(AdjListNode));
    head->vertex = vet;
    head->next = NULL;
    graph->heads[graph->size++] = head;
}

void removeVertex(GraphAdjList *graph, Vertex *vet)
{
    int i,j;
    AdjListNode *node = findNode(graph,vet);
    assert(node != NULL);
    AdjListNode *cur = node;
    AdjListNode *pre = NULL;
    while (cur)
    {
        pre = cur;
        cur = cur->next;
        free(pre);
    }
    for (i = 0; i < graph->size; i++)
    {
        cur = graph->heads[i];
        pre = NULL;
        while (cur)
        {
            pre = cur;
            cur = cur->next;
            if (cur && cur->vertex == vet)
            {
                pre->next = cur->next;
                free(cur);
                break;
            }
        }
    }
    for (i = 0; i < graph->size; i++)
    {
        if (graph->heads[i] == node)
        {
            break;
        }
    }
    for (j = i; j < graph->size - 1; j++)
    {
        graph->heads[j] = graph->heads[j + 1];
    }
    graph->size--;
    free(vet);
}

