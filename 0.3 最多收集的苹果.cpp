#include <iostream>
#include <algorithm>
using namespace std;

/*(1)Ѱ��״̬���ʽ��d[i][j] = w, ����(0,0)�ߵ�(i,j)�������õ���ƻ��Ϊw
 *(2)����״̬���ʽ�о�״̬��
 *  d[0][0]=1           d[0][1]=d[0][0]+4=5   d[0][2]=d[0][1]+3=8 ...
 *  d[1][0]=d[0][0]+2=3 d[1][1]=max{d[1][0], d[0][1]}+5=10
 *  ...
 *(3)���ݸ���״̬�ҳ���״̬����С״̬�ĵ��ƹ�ϵʽ��
 *  d[i][j] = max{d[i-1][j], d[i][j-1]}+A[i][j]
 *(4)coding
 */

int function(int **A, int m, int n);

int a[4][5] ={
    {1,4,3,4,2},
    {2,5,2,4,1},
    {1,9,4,4,1},
    {8,2,1,8,3}
};

int main()
{
    int *ptr[4];
    ptr[0] = a[0];
    ptr[1] = a[1];
    ptr[2] = a[2];
    ptr[3] = a[3];

    cout << function(ptr, 4, 5) <<endl;
}

int function(int **A, int m, int n)
{
    //1 ׼������¼
    int maxTable[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            maxTable[i][j] = 0;
        }
    }

    //2 ��ʼ����ʼ״̬

    //3 �ݹ��ϵʽ
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int left = 0, up = 0;

            //���⴦���1��
            if(i-1 < 0){
                left = 0;
            }else{
                left = maxTable[i-1][j];
            }
            //���⴦���1��
            if(j-1 < 0){
                up = 0;
            }else{
                up = maxTable[i][j-1];
            }

            maxTable[i][j] = max(
                                 (left),
                                 (up)
                                 ) + A[i][j];
        }
    }
    //4����
    return maxTable[m-1][n-1];
}
