#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    /*
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    */
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print(int a[], int num)
{
    for(int i = 0; i < num; i++){
        cout <<a[i]<<" ";
    }
    cout <<endl;
}

void HeapAdjust(int a[], int root, int end)
{
    int cur = root;

    while(1){
        int left = 2*cur+1;
        int right = 2*cur+2;

        if(left > end){
            return;
        }else if(left <= end && right > end){
            if(a[cur] < a[left]){
                swap(&a[cur], &a[left]);
            }
            cur = left;
        }else if(right <= end){
            int max = a[left] > a[right] ? left : right;
            if(a[cur] < a[max]){
                swap(&a[cur], &a[max]);
            }
            cur = max;
        }
    }
}

void HeapSort(int *a, int num)
{
    //自中向上建立big top heap
    for(int i = num/2; i >= 0; i--){
        HeapAdjust(a,i, num-1);
    }

    //heap sort
    for(int i = num-1; i > 0; i--){
        swap(&a[i], &a[0]);
        HeapAdjust(a, 0, i-1);
    }

}

int main()
{
    int a[9] = {9,1,5,8,3,7,4,6,2};

    HeapSort(a, 9);
    print(a, 9);
}
