#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

//input
int _a[3][3] = {
    {0,0,0},
    {0,1,0},
    {0,0,0}
};
int rows = 3;
int cols = 3;

//output
vector<vector<int> > a;
int maxLevel;
int num;
int UniquePaths2(int currRow, int currCol, int level)
{
    //cout <<level<<" "<<maxLevel<<endl;
    if(level >= maxLevel){

        if(currRow == rows-1 && currCol == cols-1){
            num++;
        }

        return num;
    }

    //case right
    //卡壳1：没有检查currCol+1是否越界
    if(currCol+1 < cols &&  a[currRow][currCol+1] == 0){
        //set
        currCol++;
        //recursion
        UniquePaths2(currRow, currCol, level+1);
        //repeal
        currCol--;
    }

    //case down
    if(currRow+1 < rows && a[currRow+1][currCol] == 0){
        //set
        currRow++;
        //recursion
        UniquePaths2(currRow, currCol, level+1);
        //repeal
        currCol--;
    }

    return num;
}

int main()
{
    vector<int> a0(_a[0], _a[0]+3);
    vector<int> a1(_a[1], _a[1]+3);
    vector<int> a2(_a[2], _a[2]+3);
    a.push_back(a0);
    a.push_back(a1);
    a.push_back(a2);

    maxLevel = a.front().size()-1 + a.size()-1;

    cout <<UniquePaths2(0,0,0)<<endl;
}
