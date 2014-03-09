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

    //��ֹ������Ҳ����������������ζ���ҵ���һ�����н�
    if(row ==  N){

    }

    //��row�еĻʺ����е��ж���һ��
    for(int j = 0; j < N; j++){

        //��֦����ʱ�ʺ��Ե��к��ж��Ѿ�ȷ���������жϺϷ��ԣ������ʲ��ڴ˻����ϵݹ���
        if(){
        }

        //�Ϸ����򽫵�row�еĻʺ��¼�����λ��

        //��¼�˵�row�лʺ�ĺϷ�λ�ú�ݹ��(row+1)�еĻʺ�
        dfs();

        //row��֮��ĵݹ���ɣ�Ϊ�˲�Ӱ��ǰrow�еĵݹ飬��Ҫ���������(row�е�����)���֮ǰ���ʺ��¼��ԭΪԭ��������

    }
}
