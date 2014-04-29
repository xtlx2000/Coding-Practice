#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define MAXVERTEX 100
#define MAXVALUE 65535

struct MatrixGraph
{
    int vertex[MAXVERTEX];
    int table[MAXVERTEX][MAXVERTEX];

    int vertexNum;
    int edgeNum;
};

void createGraph(struct MatrixGraph *G)
{
    G->vertexNum = 5;
    G->vertex[0] = 0;
    G->vertex[1] = 1;
    G->vertex[2] = 2;
    G->vertex[3] = 3;
    G->vertex[4] = 4;

    G->edgeNum = 6;
    for(int i = 0; i < MAXVERTEX; i++){
        for(int j = 0; j < MAXVERTEX; j++){
            G->table[i][j] = MAXVALUE;
        }
    }

    G->table[0][1] = 1;
    G->table[0][2] = 1;
    G->table[0][3] = 1;
    G->table[1][3] = 1;
    G->table[2][4] = 1;
    G->table[3][4] = 1;
    //undirected graph
    G->table[1][0] = 1;
    G->table[2][0] = 1;
    G->table[3][0] = 1;
    G->table[3][1] = 1;
    G->table[4][2] = 1;
    G->table[4][3] = 1;
}


int shortestPath(int source, int end);
vector<int> getSons(int tmpNode, set<int> &visited);
int generatePath(map<int, int> &father, int end);
void swapQueue(queue<int> **q1, queue<int> **q2);

struct MatrixGraph G;
int main()
{
    createGraph(&G);
    int num = shortestPath(0, 4);
    cout<<endl;
    cout <<num<<endl;

}

int shortestPath(int source, int end)
{
    bool found = false;
    queue<int> queue1, queue2;
    queue<int> *current = &queue1, *sons = &queue2;
    set<int> visited;
    map<int ,int> father;

    current->push(source);
    visited.insert(source);

    while(!current->empty() && !found){//1 layer-among traverse

        while(!current->empty() && !found){//2 layer-inter traverse

            int tmpNode = current->front();
            current->pop();

            vector<int> sonNodes = getSons(tmpNode, visited);

            //3 sons traverse
            for(vector<int>::iterator iter = sonNodes.begin();
                iter != sonNodes.end();
                iter++
                ){

                if(*iter == end){
                    father[*iter] = tmpNode;
                    found = true;
                    break;
                }

                sons->push(*iter);
                father[*iter] = tmpNode;
            }
        }
        queue<int> *tmpPtr = sons;
        sons = current;
        current = tmpPtr;
    }

    if(found){
        return generatePath(father, end);
    }else{
        return 0;
    }
}


vector<int> getSons(int tmpNode, set<int> &visited)
{
    vector<int> result;
    for(int j = 0; j < G.vertexNum; j++){
        if(G.table[tmpNode][j] < MAXVALUE && visited.find(j) == visited.end()){

            result.push_back(j);
        }
    }

    return result;
}
int generatePath(map<int, int> &father, int end)
{
    int tmp = end;
    int stepNum = 0;
    cout <<end<<"<-";
    while(father.find(tmp) != father.end()){
        cout <<father[tmp]<<"<-";
        tmp = father[tmp];
        stepNum++;
    }

    return stepNum;
}

void swapQueue(queue<int> **q1, queue<int> **q2)
{
    queue<int> **tmp = q1;
    q1 = q2;
    q2 = tmp;
}
