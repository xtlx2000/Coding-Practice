#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/* (1)找出状态表达式：d(i) = j，从点1到点i最短距离为j
 * (2)根据状态表达式找出各个状态：
 *  <1> 利用顶点1
        d(1)=0
 *      d(2)=1
 *      d(3)=3
 *      d(0)=1
 *  <2> 利用顶点2
        d(3)=d(2)+1=2
 *  <3> 利用顶点3
        d(4)=d(3)+2=4
 *  <4> 利用顶点0
        d(4)=d(0)+0=1
    <5> 利用顶点4

 * (3)根据各个状态找出大状态依赖小状态的递推关系式：
        d(i) = min{d(i) , (d(j)+A[j][i])}
        表示从顶点0到顶点i的最短距离为（目前0到i的最短距离 与 0到j的最短距离+j到i最短距离）的
        最小值。
 * (4)coding
 *
 */

//图的表示使用邻接矩阵
#define MAXVEX 100
#define INFINITY  65535
struct MatrixGraph
{
    int vertex[MAXVEX];
    int table[MAXVEX][MAXVEX];
    int numNodes;
    int numEdges;
};

//输入边
void inputEdge(struct MatrixGraph *G, int nodeA, int nodeB, int weight)
{
    G->table[nodeA][nodeB] = weight;
    G->table[nodeB][nodeA] = weight;
    G->numEdges++;
}


int main()
{
    //1准备已知图
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
    //1.1输入顶点
    G.vertex[0] = 1;//1代表存在顶点
    G.vertex[1] = 1;
    G.vertex[2] = 1;
    G.vertex[3] = 1;
    G.vertex[4] = 1;
    G.numNodes = 5;
    //1.2输入边
    inputEdge(&G, 0, 1, 1);
    inputEdge(&G, 0, 4, 0);
    inputEdge(&G, 1, 2, 1);
    inputEdge(&G, 1, 3, 3);
    inputEdge(&G, 2, 3, 1);
    inputEdge(&G, 3, 4, 2);

    //2准备备忘录
    int minTable[5] = {INFINITY,INFINITY,INFINITY,INFINITY,INFINITY};
    int visitedNode[5] = {0};
    int visitedEdge[5][5] = {0};

    //3初始化初始状态值
    minTable[1] = 0;

    //4 递归关系式
    queue<int> que;
    que.push(G.vertex[1]);//顶点1是源点

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
