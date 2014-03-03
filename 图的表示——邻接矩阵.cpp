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
    printf("���붥�����ͱ���:\n");
    scanf("%d %d", &G->numNodes, &G->numEdges);

    //���붥���
    for(int i = 0; i < G->numNodes; i++){
        scanf("%d", &(G->vetexs[i]));
    }

    //��ʼ���߱�
    for(int i = 0; i < G->numNodes; i++){
        for(int j = 0; j < G->numNodes; j++){
            G->table[i][j] = INFINITY;
        }
    }

    //����߱�
    for(int k = 0; k < G->numEdges; k++){
        int i,j,w;
        printf("�����(vi,vj)�ϵ��±�i,�±�j,Ȩֵw:\n");
        scanf("%d,%d,%d",&i, &j, &w);
        G->table[i][j] = w;
        G->table[j][i] = G->table[j][i];//����ͼ
    }
}

int main()
{
    MatrixGraph G;
    CreateMatrixGraph(&G);
}
