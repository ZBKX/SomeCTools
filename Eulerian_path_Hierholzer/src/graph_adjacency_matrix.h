#ifndef _graph_adjacency_matrix_h_
#define _graph_adjacency_matrix_h_

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

GraphAdjMat *newGraphAdjMat();

void delGraphAdjMat(GraphAdjMat *graph);

void addVertex(GraphAdjMat *garph, int val);

void removeVertex(GraphAdjMat *graph, int index);

int findVertex(GraphAdjMat *graph, int val);

void addEdge(GraphAdjMat *graph, int i, int j);

void removeEdge(GraphAdjMat *graph, int i, int j);

void printVertices(GraphAdjMat *graph);

void printGraphAdjMat(GraphAdjMat *graph);

#endif