#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100
#define INFINITY  65535

//边
struct Edge
{
    int vetex;
    int weight;
    struct Edge *next;
};

//顶点
struct VertexTable
{
    int vertexValue;
    Edge *firstEdge;
};

//邻接表
struct ListGraph
{
    struct VertexTable table[MAXVEX];
    int numNodes;
    int numEdges;
};

void CreateListGraph(ListGraph *G)
{
    printf("输入顶点数和边数:\n");
    scanf("%d %d", &G->numNodes, &G->numEdges);

    //建立顶点表
    for(int i = 0; i < G->numNodes; i++){
        scanf("%d", &(G->table[i].vertexValue));
        G->table[i].firstEdge = NULL;
    }

    //建立边表
    for(int k = 0; k < G->numEdges; k++){
        int i,j;
        struct Edge *e;
        printf("输入边(vi, vj)上的顶点序号:\n");
        scanf("%d,%d", &i, &j);
        e = (struct Edge *)malloc(sizeof(struct Edge));
        e->vetex = j;
        e->next = G->table[i].firstEdge;
        G->table[i].firstEdge = e;

        //无向图
        e = (struct Edge *)malloc(sizeof(struct Edge));
        e->vetex = i;
        e->next = G->table[j].firstEdge;
        G->table[j].firstEdge = e;
    }
}

int main()
{
    ListGraph G;
    CreateListGraph(&G);
}
