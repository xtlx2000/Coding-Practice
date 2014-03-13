#include <iostream>
using namespace std;

void print(int a[], int num)
{
    for(int i = 0; i < num; i++){
        cout <<a[i]<<" ";
    }
    cout <<endl;
}

void insertSort(int *a, int num)
{
    for(int i = 1; i < num; i++){
        int tmp = a[i];
        int j = i;
        for(; j > 0; j--){
            if(tmp < a[j-1]){
                a[j] = a[j-1];
            }else{
                break;
            }
        }
        a[j] = tmp;
    }
}

int main()
{
    int a[9] = {9,1,5,8,3,7,4,6,2};

    insertSort(a, 9);
    print(a, 9);
}
