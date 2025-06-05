#include "graph_adjacency_matrix.h"
//#include "graph_adjacency_list.h"
#include "hierholzer.h"
#include "dfs_bfs.h"

void addUserVertex(GraphAdjMat *graph);
void addUserEdge(GraphAdjMat *graph);

void testMat1();
void testMat2();

void testMat_DFS1();
void testMat_DFS2();

void testMat_BFS1();
void testMat_BFS2();

void testMat_Hei1();

int main(int argc, char *argv[])
{
    testMat_Hei1();
    return 0;
}

//-1退出,其它继续
void addUserVertex(GraphAdjMat *graph)
{
    int key;
    while (1)
    {
        printf("请输入节点数值:");
        scanf("%d",&key);
        if (key == -1)
        {
            break;
        }
        addVertex(graph, key);
        printf("\n");
    }
}
//任意输入值为-1时退出
void addUserEdge(GraphAdjMat *graph)
{
    int key1;
    int key2;
    while (1)
    {
        printf("请输入第一个节点数值:");
        scanf("%d",&key1);
        printf("请输入第二个节点数值:");
        scanf("%d",&key2);
        if (key1 == -1 || key2 == -1)
        {
            break;
        }
        key1 = findVertex(graph,key1);
        key2 = findVertex(graph,key2);
        addEdge(graph,key1,key2);
        printf("\n");
    }
}


/*testMat*/
void testMat1()
{
    GraphAdjMat *node = newGraphAdjMat();
    int i,j;

    addUserVertex(node);

    printf("1:\n");
    printGraphAdjMat(node);
    printVertices(node);
    
    addUserEdge(node);

    printf("2:\n");
    printGraphAdjMat(node);

    removeVertex(node,12);
    printf("3:\n");
    printGraphAdjMat(node);    

    removeEdge(node,1,1);
    printf("4:\n");
    printGraphAdjMat(node);

    delGraphAdjMat(node);
}

void testMat2()
{
    GraphAdjMat *node = newGraphAdjMat();
    int i,j;

    for (i = 17; i > 0; i--)
    {
        addVertex(node, i);
        
    }
    printf("1:\n");
    printGraphAdjMat(node);
    printVertices(node);
    
    for (i = 1; i < 17; i++)
    {
        for (j = 1 ; j < 17; j++)
        {
            if (j % 2 == 0)
            {
                addEdge(node, i-1 , j-1);
                
            }
        }
    }
    printf("2:\n");
    printGraphAdjMat(node);

    removeVertex(node,12);
    printf("3:\n");
    printGraphAdjMat(node);    

    removeEdge(node,1,1);
    printf("4:\n");
    printGraphAdjMat(node);

    delGraphAdjMat(node);
}
/*testMat*/
/*testMat_DFS*/
void testMat_DFS1()
{
    GraphAdjMat *node = newGraphAdjMat();
    int i,j;

    for (i = 17; i > 0; i--)
    {
        addVertex(node, i);
        
    }
    printf("1:\n");
    printGraphAdjMat(node);
    printVertices(node);
    
    for (i = 1; i < 17; i++)
    {
        for (j = 1 ; j < 17; j++)
        {
            if (j % 2 == 0)
            {
                addEdge(node, i-1 , j-1);
                
            }
        }
    }

    printf("2:\n");
    printGraphAdjMat(node);

    DFSList *list = newDFSList(node);

    DFS(node,list,0);

    delDFSList(list);

    removeVertex(node,12);
    printf("3:\n");
    printGraphAdjMat(node);    

    removeEdge(node,1,1);
    printf("4:\n");
    printGraphAdjMat(node);

    DFSList *list2 = newDFSList(node);

    DFS(node,list2,0);

    delDFSList(list2);

    delGraphAdjMat(node);
}

void testMat_DFS2()
{
    GraphAdjMat *node = newGraphAdjMat();
    int i,j;

    addUserVertex(node);

    printf("1:\n");
    printGraphAdjMat(node);
    printVertices(node);
    
    addUserEdge(node);

    printf("2:\n");
    printGraphAdjMat(node);

    DFSList *list = newDFSList(node);

    printf("请输入开始节点数值:");
    scanf("%d",&j);

    j = findVertex(node,j);

    DFS(node,list,j);

    delDFSList(list);

    removeVertex(node,12);
    printf("3:\n");
    printGraphAdjMat(node);    

    removeEdge(node,1,1);
    printf("4:\n");
    printGraphAdjMat(node);

    DFSList *list2 = newDFSList(node);

    printf("请输入开始节点数值:");
    scanf("%d",&j);

    j = findVertex(node,j);

    DFS(node,list2,j);

    delDFSList(list2);

    delGraphAdjMat(node);
}
/*testMat_DFS*/
/*testMat_BFS*/
void testMat_BFS1()
{
    GraphAdjMat *node = newGraphAdjMat();
    int i,j;

    for (i = 17; i > 0; i--)
    {
        addVertex(node, i);
        
    }
    printf("1:\n");
    printGraphAdjMat(node);
    printVertices(node);
    
    for (i = 1; i < 17; i++)
    {
        for (j = 1 ; j < 17; j++)
        {
            if (j >= 0)
            {
                addEdge(node, i-1 , j-1);
            }
        }
    }

    printf("2:\n");
    printGraphAdjMat(node);

    BFSList *list = newBFSList(node);

    BFS(node,list,2);

    delBFSList(list);

    removeVertex(node,12);
    printf("3:\n");
    printGraphAdjMat(node);    

    removeEdge(node,1,1);
    printf("4:\n");
    printGraphAdjMat(node);

    BFSList *list2 = newBFSList(node);

    BFS(node,list2,2);

    delBFSList(list2);

    delGraphAdjMat(node);
}

void testMat_BFS2()
{
    GraphAdjMat *node = newGraphAdjMat();
    int i,j;

    addUserVertex(node);

    printf("1:\n");
    printGraphAdjMat(node);
    printVertices(node);
    
    addUserEdge(node);

    printf("2:\n");
    printGraphAdjMat(node);

    BFSList *list = newBFSList(node);

    printf("请输入开始节点数值:");
    scanf("%d",&j);

    j = findVertex(node,j);

    BFS(node,list,j);

    delBFSList(list);

    removeVertex(node,12);
    printf("3:\n");
    printGraphAdjMat(node);    

    removeEdge(node,1,1);
    printf("4:\n");
    printGraphAdjMat(node);

    BFSList *list2 = newBFSList(node);

    printf("请输入开始节点数值:");
    scanf("%d",&j);

    j = findVertex(node,j);

    BFS(node,list2,j);

    delBFSList(list2);

    delGraphAdjMat(node);
}

/*testMat_BFS*/
/*testMat_Hei*/
void testMat_Hei1()
{
    GraphAdjMat *node = newGraphAdjMat();
    int i;

    addUserVertex(node);

    printf("1:\n");
    printGraphAdjMat(node);
    printVertices(node);
    
    addUserEdge(node);

    printf("2:\n");
    printGraphAdjMat(node);

    HieList *list = newHieList(node);

    CheckEulerianPath(list);

    int strat = StratHieNode(list);

    Hieholzer(list,strat);

    printHieholzer(list);

    delGraphAdjMat(node);
}
/*testMat_Hei*/
