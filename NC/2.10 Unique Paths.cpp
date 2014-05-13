#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

//input
int rows = 3;
int cols = 5;

//output
int num;
int maxLevel = (rows-1) + (cols-1);
int UniquePaths(int currRow, int currCol, int level)
{
    //cout <<currRow<<" "<<currCol<<endl;
    //leafnode
    //卡壳1：一开始对这个结束条件想错了，想成了if(currRow >= rows || currCol >= cols)就返回了，想想就不对嘛!
    if(level >= maxLevel){

        if(currRow == rows-1 && currCol == cols-1){
            num++;
        }

        return num;
    }

    //case "right"
    //set
    currCol++;
    //recursion
    UniquePaths(currRow, currCol, level+1);
    //repeal
    currCol--;


    //case "down"
    //set
    currRow++;
    //recursion
    UniquePaths(currRow, currCol, level+1);
    //repeal
    currRow--;

    return num;

}

int main()
{
    cout << UniquePaths(0, 0, 0) << endl;
}
