#include <iostream>
using namespace std;

void merge(int *a, int start, int mid, int end);
void mergeSort(int *a, int start, int end)
{
    if(start < end){
        int mid = (start + end)/2;
        mergeSort(a, start, mid);
        mergeSort(a, mid+1, end);
        merge(a, start, mid, end);
    }
}

void merge(int *a, int start, int mid, int end)
{
    int num = end-start+1;
    int b[num];
    int index1 = start, index2 = mid+1;
    int index = 0;

    while(index1 <= mid && index2 <= end){

        if(a[index1] <= a[index2]){
            b[index++] = a[index1++];
        }else{
            b[index++] = a[index2++];
        }
    }

    while(index1 <= mid){
        b[index++] = a[index1++];
    }

    while(index2 <= end){
        b[index++] = a[index2++];
    }

    for(int i = start, j = 0; i <= end; i++,j++){
        a[i] = b[j];
    }
}

void print(int *a, int num)
{
    for(int i = 0; i < num; i++){
        cout <<a[i] << " ";
    }
    cout <<endl;
}

int main()
{
    int a[7] = {3,2,6,9,1,4,5};
    mergeSort(a, 0, 6);
    print(a, 7);
}
