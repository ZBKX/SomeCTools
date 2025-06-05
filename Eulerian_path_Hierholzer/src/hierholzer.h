#ifndef _hierholzer_h_
#define _hierholzer_h_

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "dfs_bfs.h"
#include "graph_adjacency_matrix.h"

HieList *newHieList(GraphAdjMat *graph);

void CheckEulerianPath(HieList *list);

int findHieVertex(HieList *list, int val);

int StratHieNode (HieList *list);

void Hieholzer(HieList *list, int strat);

void printHieholzer(HieList *list);

#endif