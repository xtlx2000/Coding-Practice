#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

//1 状态表达式 d[i][j] = min{d[i-1][j-1], d[i-1][j+1]} + a[i][j]
//2 各个状态
//              a[0][3] = 2
//      a[1][2]=2+3=5   a[1][4]=2+4=6
//     ..   ..          ..          ..
//
//3 由各个状态推出小状态表示大状态推出递推关系式
//      d[i][j] = min{d[i-1][j-1], d[i-1][j+1]} + a[i][j]
//4 coding
struct coordinate
{
    int x;
    int y;
    coordinate(int x_, int y_){
        x = x_;
        y = y_;
    }
};

int a[4][7]={
    {-1,-1,-1, 2,-1,-1,-1},
    {-1,-1, 3,-1, 4,-1,-1},
    {-1, 6,-1, 5,-1, 7,-1},
    { 4,-1, 1,-1, 8,-1, 3}
};

int minPathSum(int a[4][7], int rows, int cols)
{
    //1 准备备忘录
    int MinSum = 65535;
    int minArr[rows][cols];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            minArr[i][j] = -1;
        }
    }
    queue<struct coordinate> que;

    //2 初始化初始状态
    minArr[0][cols/2] = a[0][cols/2];
    que.push(coordinate(0, cols/2));

    //3 递推关系式
    while(!que.empty()){
        struct coordinate tmp = que.front();
        que.pop();

        int minSum;
        bool leftParent = false;
        bool rightParent = false;

        //检查左父亲是否存在
        if(tmp.x-1 < 0 || tmp.y-1 < 0){
            leftParent = false;
        }else{
            if(a[tmp.x-1][tmp.y-1] == -1){
                leftParent = false;
            }else{
                leftParent = true;
            }
        }

        //检查右父亲是否存在
        if(tmp.x-1 < 0 || tmp.y+1 < 0){
            leftParent = false;
        }else{
            if(a[tmp.x-1][tmp.y+1] == -1){
                rightParent = false;
            }else{
                rightParent = true;
            }
        }

        if(leftParent && !rightParent){
            minSum = minArr[tmp.x-1][tmp.y-1] + a[tmp.x][tmp.y];
        }else if(!leftParent && rightParent){
            minSum = minArr[tmp.x-1][tmp.y+1] + a[tmp.x][tmp.y];
        }else if(leftParent && rightParent){
            int parentSum = min(minArr[tmp.x-1][tmp.y-1], minArr[tmp.x-1][tmp.y+1]);
            minSum = parentSum + a[tmp.x][tmp.y];
        }else if(!leftParent && !rightParent){
            minSum = a[tmp.x][tmp.y];
        }
        minArr[tmp.x][tmp.y] = minSum;
        //cout <<"minArr["<<tmp.x<<"]["<<tmp.y<<"]="<<minSum<<endl;

        if(tmp.x+1 < rows){
            que.push(coordinate(tmp.x+1, tmp.y-1));
            que.push(coordinate(tmp.x+1, tmp.y+1));
        }
    }

    for(int i = 0; i < cols; i++){
        //cout<<rows-1<<" "<<i<<" "<<minArr[rows-1][i]<<endl;
        if(a[rows-1][i] == -1){
            continue;
        }

        if(MinSum > minArr[rows-1][i]){
            MinSum = minArr[rows-1][i];

        }
    }

    return MinSum;

}

int main()
{
    cout <<minPathSum(a,4,7) <<endl;
}
