#include <iostream>
using namespace std;

void print(int a[], int num)
{
    for(int i = 0; i < num; i++){
        cout <<a[i]<<" ";
    }
    cout <<endl;
}

void shellSort(int *a, int num)
{
    int increament = num-1;

    do{
        increament = increament/3 + 1;

        for(int i = 0; i+increament < num; i++){
            int j = i+increament;
            int tmp = a[j];

            for(; j >= increament; j -= increament){
                if(tmp < a[j-increament]){
                    a[j] = a[j-increament];
                }else{
                    break;
                }
            }
            a[j] = tmp;
        }

    }while(increament > 1);
}

int main()
{
    int a[9] = {9,1,5,8,3,7,4,6,2};

    shellSort(a, 9);
    print(a, 9);
}
