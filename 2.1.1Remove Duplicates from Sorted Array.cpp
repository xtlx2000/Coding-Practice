#include <iostream>
using namespace std;

class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        if(n == 0) return 0;

        int index = 0;
        for(int i = 1; i < n; i++){
            if(A[index] != A[i]){
                A[++index] = A[i];
            }
        }

        return index + 1;
    }
};

int a[5] = {1,1,1,2,3};

int main()
{
    Solution s;
    int num = s.removeDuplicates(a, 5);
    cout <<num<<endl;
}
