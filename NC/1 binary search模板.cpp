#include <iostream>
using namespace std;

/*
 * 关键点：
 * 1 start + 1 < end
 * 2 start + (end - start) + 1
 * 3 A[start] == target && A[end] == target
 */

/*
 * 习题：
 * 1 leetcode: Search Insert Position，因此插入排序其实是可以用二分搜索优化的
 * 2 leetcode: search for a range
 * 3 leetcode: search in rotated array
 * 4
 *
 *
 *
 *
 */

int binarySearch(int A[], int start, int end, int target)
{
    while(start + 1 < end){
        int mid = start + (end - start) / 2;
        if(A[mid] == target){
            return mid;
        }else if(A[mid] < target){
            start = mid;
        }else{
            end = mid;
        }
    }

    if(A[start] == target){
        return start;
    }
    if(A[end] == target){
        return end;
    }

    return -1;
}

int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    cout <<binarySearch(a, 0, 9, 0)<<endl;
    cout <<binarySearch(a, 0, 9, 1)<<endl;
    cout <<binarySearch(a, 0, 9, 2)<<endl;
    cout <<binarySearch(a, 0, 9, 3)<<endl;
    cout <<binarySearch(a, 0, 9, 4)<<endl;
    cout <<binarySearch(a, 0, 9, 5)<<endl;
    cout <<binarySearch(a, 0, 9, 6)<<endl;
    cout <<binarySearch(a, 0, 9, 7)<<endl;
    cout <<binarySearch(a, 0, 9, 8)<<endl;
    cout <<binarySearch(a, 0, 9, 9)<<endl;
    cout <<binarySearch(a, 0, 9, 10)<<endl;
    cout <<binarySearch(a, 0, 9, 11)<<endl;
}




