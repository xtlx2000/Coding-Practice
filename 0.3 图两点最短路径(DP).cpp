#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/* (1)�ҳ�״̬���ʽ��d(i) = j���ӵ�1����i��̾���Ϊj
 * (2)����״̬���ʽ�ҳ�����״̬��
 *  <1> ���ö���1
        d(1)=0
 *      d(2)=1
 *      d(3)=3
 *      d(0)=1
 *  <2> ���ö���2
        d(3)=d(2)+1=2
 *  <3> ���ö���3
        d(4)=d(3)+2=4
 *  <4> ���ö���0
        d(4)=d(0)+0=1
    <5> ���ö���4

 * (3)���ݸ���״̬�ҳ���״̬����С״̬�ĵ��ƹ�ϵʽ��
        d(i) = min{d(i) , (d(j)+A[j][i])}
        ��ʾ�Ӷ���0������i����̾���Ϊ��Ŀǰ0��i����̾��� �� 0��j����̾���+j��i��̾��룩��
        ��Сֵ��
 * (4)coding
 *
 */

//ͼ�ı�ʾʹ���ڽӾ���
#define MAXVEX 100
#define INFINITY  65535
struct MatrixGraph
{
    int vertex[MAXVEX];
    int table[MAXVEX][MAXVEX];
    int numNodes;
    int numEdges;
};

//�����
void inputEdge(struct MatrixGraph *G, int nodeA, int nodeB, int weight)
{
    G->table[nodeA][nodeB] = weight;
    G->table[nodeB][nodeA] = weight;
    G->numEdges++;
}


int main()
{
    //1׼����֪ͼ
    MatrixGraph G;
    for(int i = 0; i < MAXVEX; i++){
        G.vertex[i] = 0;
    }
    G.numNodes = 0;
    for(int i = 0; i < MAXVEX; i++){
        for(int j = 0; j < MAXVEX; j++){
            G.table[i][j] = INFINITY;
        }
    }
    G.numEdges = 0;
    //1.1���붥��
    G.vertex[0] = 1;//1������ڶ���
    G.vertex[1] = 1;
    G.vertex[2] = 1;
    G.vertex[3] = 1;
    G.vertex[4] = 1;
    G.numNodes = 5;
    //1.2�����
    inputEdge(&G, 0, 1, 1);
    inputEdge(&G, 0, 4, 0);
    inputEdge(&G, 1, 2, 1);
    inputEdge(&G, 1, 3, 3);
    inputEdge(&G, 2, 3, 1);
    inputEdge(&G, 3, 4, 2);

    //2׼������¼
    int minTable[5] = {INFINITY,INFINITY,INFINITY,INFINITY,INFINITY};
    int visitedNode[5] = {0};
    int visitedEdge[5][5] = {0};

    //3��ʼ����ʼ״ֵ̬
    minTable[1] = 0;

    //4 �ݹ��ϵʽ
    queue<int> que;
    que.push(G.vertex[1]);//����1��Դ��

    while(!que.empty()){
        int tmpNode = que.front();
        que.pop();

        for(int i = 0; i < MAXVEX; i++){
            if(
               (G.table[tmpNode][i] != INFINITY)
               &&
               (visitedEdge[tmpNode][i] == 0)
               ){

                if(visitedNode[i] == 0){
                    que.push(i);
                }

                minTable[i] = min(
                                  (minTable[i]),
                                  (minTable[tmpNode]+G.table[tmpNode][i])
                                  );

                visitedEdge[tmpNode][i] = 1;
                visitedEdge[i][tmpNode] = 1;
            }
        }

        visitedNode[tmpNode] = 1;
    }

    cout <<minTable[4]<<endl;
}
