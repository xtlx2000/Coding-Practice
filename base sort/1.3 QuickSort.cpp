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

void QuickSort(int a[], int start, int end)
{
}


int main()
{
    int a[9] = {9,1,5,8,3,7,4,6,2};

    QuickSort(a, 0, 8);
    print(a, 9);
}
