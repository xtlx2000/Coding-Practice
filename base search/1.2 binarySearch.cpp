#include <iostream>
using namespace std;

int binarySearch(int *a, int num, int target)
{
    int start = 0;
    int end = num-1;

    while(start <= end){
        int mid = (start+end)/2;
        if(a[mid] == target){
            return mid;
        }else if(a[mid] < target){
            start = mid+1;
        }else if(a[mid] > target){
            end = end-1;
        }
    }
    return -1;
}

int main()
{
    int a[9] = {1,2,3,4,5,6,7,8,9};
    cout <<binarySearch(a, 9, 1)<<endl;
    cout <<binarySearch(a, 9, 2)<<endl;
    cout <<binarySearch(a, 9, 9)<<endl;
    cout <<binarySearch(a, 9, 41)<<endl;
}
