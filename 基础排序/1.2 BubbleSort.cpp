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

void BubbleSort(int *a, int num)
{
    for(int i = 0; i < num-1; i++){
        for(int j = num-1; j > i; j--){
            if(a[j] < a[j-1]){
                swap(&a[j], &a[j-1]);
            }
        }
    }
}

int main()
{
    int a[9] = {9,1,5,8,3,7,4,6,2};

    BubbleSort(a, 9);
    print(a, 9);
}
