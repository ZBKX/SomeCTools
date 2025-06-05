#ifndef _dfs_bfs_h_
#define _dfs_bfs_h_

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

DFSList *newDFSList(GraphAdjMat *graph);

BFSList *newBFSList(GraphAdjMat *graph);

void delDFSList(DFSList *list);

void delBFSList(BFSList *list);

void InQueue(BFSList *list,int num);

int OutQueue(BFSList *list);

int isEmpty(BFSList *list);

void DFS(GraphAdjMat *graph, DFSList *list, int val);

void BFS(GraphAdjMat *graph, BFSList *list, int val);

#endif