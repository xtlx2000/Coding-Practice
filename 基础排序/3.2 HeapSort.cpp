#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
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
    for(int i = 2*root+1; i <= end; j *= 2){
        if(a[i] a[i+1])
    }
}

void HeapSort(int *a, int num)
{
    //自中向上建立heap
    for(int i = num/2+1; i >= 0; i--){
        HeapAdjust(a,);
    }

    //heap sort
    for(int i = num-1； i > 0; i--){
        swap(&a[num-1], &a[0]);
        HeapAdjust(a,);
    }
}

int main()
{
    int a[9] = {9,1,5,8,3,7,4,6,2};

    HeapSort(a, 9);
    print(a, 9);
}
