#ifndef _struct_h_
#define _struct_h_

#define MAX_SIZE 1024

typedef struct {
    int vertices[MAX_SIZE];
    int adjMat[MAX_SIZE][MAX_SIZE];
    int size;
}GraphAdjMat;

typedef struct DFSList{
    int visit[MAX_SIZE];
    int size;
}DFSList;

typedef struct BFSList{
    int queue[MAX_SIZE];
    int visit[MAX_SIZE];
    int end;
    int head;
    int size;
}BFSList;

typedef struct HieList{
    int odd[3];
    int oddindex;
    int even[MAX_SIZE];
    int evenindex;
    int vertices[MAX_SIZE];
    int adjMat[MAX_SIZE][MAX_SIZE];
    int size;
    int stack[MAX_SIZE];
    int top;
}HieList;

#endif