#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<string> > solveNQueues(int n);
private:
    vector<int> columns;
    vector<int> main_diag;
    vector<int> anti_diag;
    void dfs(vector<int> &C, vector<vector<string> > &result, int row);
};

int main()
{
    /*
    Solution s;
    vector<vector<string> > result = s.solveNQueues(8);

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout <<result[i][j]<<" ";
        }
        cout <<endl;
    }
    */
    vector<int> C(5, 0);
    cout <<C.size()<<endl;

}

vector<vector<string> >  Solution::solveNQueues(int n)
{
    this->columns = vector<int>(n, 0);
    this->main_diag = vector<int>(2*n, 0);
    this->anti_diag = vector<int>(2*n, 0);

    vector<vector<string> > result;
    vector<int> C(n, 0);
    dfs(C, result, 0);
    return result;
}


void Solution::dfs(vector<int> &C, vector<vector<string> > &result, int row)
{
    const int N = C.size();

    //终止条件，也就是收敛条件，意味着找到了一个可行解
    if(row ==  N){

    }

    //第row行的皇后将所有的列都试一遍
    for(int j = 0; j < N; j++){

        //剪枝：此时皇后尝试的行和列都已经确定，现在判断合法性，不合适不在此基础上递归了
        if(){
        }

        //合法，则将第row列的皇后记录在这个位置

        //记录了第row列皇后的合法位置后递归第(row+1)行的皇后
        dfs();

        //row行之后的递归完成，为了不影响前row行的递归，需要在这次搜索(row行的搜索)完成之前将皇后记录复原为原来的样子

    }
}
