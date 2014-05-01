#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

//����1���벻��˼·����ô����������û�б�XΧס��O�أ�
//˼·�� ��û�б�Χס��O��Χס��O������
//       ��Χס��O���϶�O��Χȫ����X
//       û��Χס��O���϶���Χ��O��ͨ��߽�
//       �����������ֵķ���������߽�ûO����ȫ��O����Χס������߽���O�����߽�O�������������ڵ�Oһ����û�б�Χס�ģ����εݹ�ֱ���ҵ�����û�б�Χס��O��


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

//����3����һ�����ݴ洢(x,y)����ķ�����
int enqueue(int i, int j)
{
    if(0 <= i && i <= N-1 && 0 <= j && j <= M-1){
        que.push(i*N + j);
    }
}

void recursionSet(int i, int j)
{
    //ע���4��д�ݹ���Ӧ��ע��ĵط���ʲô�ݹ������ʲôʱ��ʼ�ݹ飡
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
        //����2��queue�������ɾ����ѯ
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
