#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}


//swap sort
void swapSort(int a[], int num)
{
    for(int i = 0; i < num-1; i++){
        for(int j = i+1; j < num; j++){
            if(a[i] > a[j]){
                swap(&a[i], &a[j]);
            }
        }
    }
}

void print(int a[], int num)
{
    for(int i = 0; i < num; i++){
        cout <<a[i]<<" ";
    }
    cout <<endl;
}

int main()
{
    int a[9] = {9,1,5,8,3,7,4,6,2};

    swapSort(a, 9);
    print(a, 9);
}
