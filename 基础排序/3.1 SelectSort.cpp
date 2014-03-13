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

void selectSort(int a[], int num)
{
    for(int i = 0; i < num-1; i++){

        int min = a[i];
        int index = i;
        for(int j = i; j < num; j++){
            if(min > a[j]){
                min = a[j];
                index = j;
            }
        }
        cout <<index<<" "<<i<<endl;
        swap(&a[index], &a[i]);
        print(a, 9);
    }
}


int main()
{
    int a[9] = {9,1,5,8,3,7,4,6,2};

    selectSort(a, 9);
    print(a, 9);

}
