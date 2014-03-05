#include <iostream>
#include <algorithm>
using namespace std;

/*
 * 1��merge 2���������飬return C[k]��ʱ�临�Ӷ�O(m+n)���ռ临�Ӷ�O(m+n)
 */

/*
 * 2����2���α�ֱ����2���������飬O(k)�����ҵ���ʱ�临�Ӷ�O(k)=O(m+n)���ռ临�Ӷ�O(1)
 */

/*
 * 3������2�����������������
 */

int function(int *a, int num_a, int *b, int num_b, int k);

int main()
{
    int a[5] = {1,3,5,7,9};
    int b[5] = {2,4,6,8,10};

    cout <<function(a, 5, b, 5, 7)<<endl;
}

int function(int *a, int num_a, int *b, int num_b, int k)
{
    if(num_a > num_b){
        return function(b, num_b, a, num_a, k);
    }
    if(num_a == 0){
        return b[k-1];
    }
    if(k == 1){
        return min(a[0], b[0]);
    }

    int tmp_a = min(k/2, num_a);
    int tmp_b = min(k/2, num_b);

    if(a[tmp_a-1] == b[tmp_b-1]){
        return a[tmp_a-1];

    }else if(a[tmp_a-1] < b[tmp_a-1]){
        return function(a+tmp_a, num_a-tmp_a, b, num_b, k-tmp_a);

    }else if(a[tmp_a-1] > b[tmp_a-1]){
        return function(a, num_a, b+tmp_b, num_b-tmp_b, k-tmp_b);
    }
}
