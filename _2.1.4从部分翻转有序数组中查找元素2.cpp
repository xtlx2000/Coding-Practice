#include <iostream>
using namespace std;

int function(int *a, int num, int target);

int main()
{
    int a[6] = {1,3,1,1,1,1};

    cout <<function(a, 6, 0) <<endl;
    cout <<function(a, 6, -1) <<endl;
    cout <<function(a, 6, 3) <<endl;
}

int function(int *a, int num, int target)
{
    int first = 0;
    int last = num-1;

    while(first < last){
        int mid = (first + last)/2;

        if(a[mid] == target){
            return mid;
        }

        //前半部分有序的情况
        if(a[first] < a[mid]){
            if(a[first] < target && target < a[mid]){
                last = mid;
            }else{
                first = mid+1;
            }

        //后半部分有序的情况
        }else if(a[first] > a[mid]){

            if(a[mid] < target && target < a[last]){
                first = mid+1;
            }else{
                last = mid;
            }
        }else if(a[first] == a[mid]){
            first++;
        }
    }

    return -1;
}
