#include <iostream>
using namespace std;

class Solution1
{
public:
    void merge(int a[], int m, int b[], int n){
        int ia = 0, ib = 0, icur = 0;
        int tmpArray[m+n];

        while(ia < m && ib < n){
            tmpArray[icur++] = a[ia] >= b[ib] ? b[ib++] : a[ia++];
        }
        while(ia < m){
            tmpArray[icur++] = a[ia++];
        }
        while(ib < n){
            tmpArray[icur++] = b[ib++];
        }

        for(int i = 0; i < m+n; i++){
            a[i] = tmpArray[i];
        }
    }
};

class Solution2
{
public:
    void merge(int a[], int m, int b[], int n){
        int ia = m - 1, ib = n - 1, icur = m+n-1;

        while(ia >= 0 && ib >= 0){
            a[icur--] = a[ia] >= b[ib] ? a[ia--] : b[ib--];
        }
        while(ib >= 0){
            a[icur--] = b[ib--];
        }
    }
};

int main()
{
    int a1[12] = {1,3,5,7,9,11};
    int b1[6] = {2,4,6,8,10,12};
    Solution2 s2;
    s2.merge(a1, 6, b1, 6);
    for(int i = 0; i < 12; i++){
        cout <<a1[i]<<" ";
    }
    cout <<endl;

    int a2[12] = {1,3,5,7,9,11};
    int b2[6] = {2,4,6,8,10,12};
    Solution1 s1;
    s1.merge(a2, 6, b2, 6);
    for(int i = 0; i < 12; i++){
        cout <<a2[i]<<" ";
    }
    cout <<endl;
}
