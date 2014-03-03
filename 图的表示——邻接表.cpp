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

//��
struct Edge
{
    int vetex;
    int weight;
    struct Edge *next;
};

//����
struct VertexTable
{
    int vertexValue;
    Edge *firstEdge;
};

//�ڽӱ�
struct ListGraph
{
    struct VertexTable table[MAXVEX];
    int numNodes;
    int numEdges;
};

void CreateListGraph(ListGraph *G)
{
    printf("���붥�����ͱ���:\n");
    scanf("%d %d", &G->numNodes, &G->numEdges);

    //���������
    for(int i = 0; i < G->numNodes; i++){
        scanf("%d", &(G->table[i].vertexValue));
        G->table[i].firstEdge = NULL;
    }

    //�����߱�
    for(int k = 0; k < G->numEdges; k++){
        int i,j;
        struct Edge *e;
        printf("�����(vi, vj)�ϵĶ������:\n");
        scanf("%d,%d", &i, &j);
        e = (struct Edge *)malloc(sizeof(struct Edge));
        e->vetex = j;
        e->next = G->table[i].firstEdge;
        G->table[i].firstEdge = e;

        //����ͼ
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
