#include <iostream>
using namespace std;

class Solution
{
public:
    int search(int A[], int n, int target)
    {
        int first = 0, last = n;

        while(first != last){
            const int mid = (first + last)/2;
            if(A[mid] == target){
                return mid;
            }else if(A[first] <= A[mid]){
                if(A[first] <= target && target < A[mid]){
                    last = mid;
                }else{
                    first = mid + 1;
                }
            }else{
                if(A[mid] < target && target <= A[last - 1]){
                    first = mid +1;
                }else{
                    last = mid;
                }
            }
        }

        return -1;
    }
};

int main()
{
    int a[9] = {4,5,6,7,8,0,1,2,3};
    Solution s;
    cout <<s.search(a, 9, 1)<<endl;
}