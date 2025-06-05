#ifndef _graph_adjacency_list_h_
#define _graph_adjacency_list_h_

#define MAX_SIZE 1024

#include <stdlib.h>
#include <stdio.h>

typedef struct Vertex{
    int val;
}Vertex;

typedef struct VertexList{
    Vertex *list[MAX_SIZE];
    int size;
}VertexList;

typedef struct AdjListNode{
    Vertex *vertex;
    struct AdjListNode *next; 
}AdjListNode;

typedef struct GraphAdjList{
    AdjListNode *heads[MAX_SIZE];
    int size;
}GraphAdjList;

AdjListNode *findNode(GraphAdjList *graph, Vertex *vet);

void addEdgeHelper(AdjListNode *head, Vertex *vet);

void removeEdgeHelper(AdjListNode *head, Vertex *vet);

GraphAdjList *newGraphAdjList();

Vertex *newVertex(int val);

void addVertexList(VertexList *list, Vertex *vet);

Vertex *findVertex(VertexList *list, int val);

void delVertex(VertexList *list,int val);

void delGraphAdjList(GraphAdjList *graph);

void addEdge(GraphAdjList *graph, Vertex *vet1, Vertex *vet2);

void removeEdge(GraphAdjList *graph, Vertex *vet1, Vertex *vet2);

void addVertex(GraphAdjList *graph, Vertex *vet);

void removeVertex(GraphAdjList *graph, Vertex *vet);

#endif