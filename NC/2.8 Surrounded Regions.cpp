#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

//卡壳1：想不出思路，怎么才能区分有没有被X围住的O呢？
//思路： 想没有被围住的O和围住的O的区别
//       被围住的O：肯定O周围全部是X
//       没被围住的O：肯定周围有O能通向边界
//       因此想出来区分的方法，如果边界没O，则全部O都被围住，如果边界有O，看边界O的上下左右相邻的O一定是没有被围住的，依次递归直到找到所有没有被围住的O。


//input
vector<vector<char> > a;
char _a[4][4] = {
    {'X','X','X','X'},
    {'X','O','O','X'},
    {'X','X','O','X'},
    {'X','O','X','X'}
};
int N = 4;
int M = 4;


//output
queue<int> que;

//亮点3：用一个数据存储(x,y)坐标的方法！
int enqueue(int i, int j)
{
    if(0 <= i && i <= N-1 && 0 <= j && j <= M-1){
        que.push(i*N + j);
    }
}

void recursionSet(int i, int j)
{
    //注意点4：写递归最应该注意的地方是什么递归结束，什么时候开始递归！
    if(0 <= i && i <= N-1 && 0 <= j && j <= M-1){

        if(a[i][j] == 'O'){
            a[i][j] = '+';

            recursionSet(i-1, j);
            recursionSet(i+1, j);
            recursionSet(i, j-1);
            recursionSet(i, j+1);
        }
    }
}

void SurroundedRegions(vector<vector<char> > &a, int n, int m)
{
    for(int i = 0; i < N; i++){
        //卡壳2：queue不会插入删除查询
        //queue.front()
        //queue.push()
        //queue.pop()
        enqueue(i, 0);
        enqueue(i, M-1);
    }
    for(int i = 1; i < M-1; i++){
        enqueue(0, i);
        enqueue(N-1, i);
    }


    while(!que.empty()){

        int point = que.front();
        que.pop();
        int row = point / N;
        int col = point % N;
        //cout <<row<<" "<<col<<endl;

        //recursion
        recursionSet(row, col);
    }


    for(int i = 0; i < N; i++){

        for(int j = 0; j < M; j++){

            if(a[i][j] == 'O'){
                a[i][j] = 'X';
            }else if(a[i][j] == '+'){
                a[i][j] = 'O';
            }
        }
    }

}

int main()
{
    //input
    vector<char> a0(_a[0], _a[0]+4);
    vector<char> a1(_a[1], _a[1]+4);
    vector<char> a2(_a[2], _a[2]+4);
    vector<char> a3(_a[3], _a[3]+4);
    a.push_back(a0);
    a.push_back(a1);
    a.push_back(a2);
    a.push_back(a3);

    for(int i = 0; i < N; i++){

        for(int j = 0; j < M; j++){
            cout <<a[i][j]<< " ";
        }
        cout <<endl;
    }
    cout <<endl;

    SurroundedRegions(a, N, M);

    for(int i = 0; i < N; i++){

        for(int j = 0; j < M; j++){
            cout <<a[i][j]<< " ";
        }
        cout <<endl;
    }
}
