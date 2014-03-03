#include <iostream>
#include <stdio.h>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100
#define INFINITY  65535

struct MatrixGraph
{
    int vetexs[MAXVEX];
    int table[MAXVEX][MAXVEX];
    int numNodes;
    int numEdges;
};

void CreateMatrixGraph(struct MatrixGraph *G)
{
    printf("输入顶点数和边数:\n");
    scanf("%d %d", &G->numNodes, &G->numEdges);

    //输入顶点表
    for(int i = 0; i < G->numNodes; i++){
        scanf("%d", &(G->vetexs[i]));
    }

    //初始化边表
    for(int i = 0; i < G->numNodes; i++){
        for(int j = 0; j < G->numNodes; j++){
            G->table[i][j] = INFINITY;
        }
    }

    //输入边表
    for(int k = 0; k < G->numEdges; k++){
        int i,j,w;
        printf("输入边(vi,vj)上的下标i,下标j,权值w:\n");
        scanf("%d,%d,%d",&i, &j, &w);
        G->table[i][j] = w;
        G->table[j][i] = G->table[j][i];//无向图
    }
}

int main()
{
    MatrixGraph G;
    CreateMatrixGraph(&G);
}
