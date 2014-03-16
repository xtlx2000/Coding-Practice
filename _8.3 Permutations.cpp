#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print(int *a, int num)
{
    for(int i = 0; i < num; i++){
        cout <<a[i]<< " ";
    }
    cout <<endl;
}

void reverseArray(int *a, int num)
{
    int end = 0;
    if(num % 2 == 0){
        end = num/2-1;
    }else{
        end = num/2;
    }

    for(int i = 0; i <= end; i++){
        swap(&a[i], &a[num-1-i]);
    }
}

void nextPermutation(int *a, int num)
{
    //1 find the first not increase index :tmp
    int tmp = -1;
    for(int i = num-1; i > 0; i--){
        if(a[i] >= a[i-1]){
            tmp = i-1;
            break;
        }
    }

    //2 find the first index bigger than a[tmp] :bigger
    int bigger = -1;
    for(int i = num-1; i >= 0; i--){
        if(a[i] > a[tmp]){
            bigger = i;
            break;
        }
    }

    //3 change a[tmp] and [bigger]
    swap(&a[tmp], &a[bigger]);

    //4 reverse array[tmp+1...]
    reverseArray(&a[tmp+1], (num-1)-tmp);
}


int main()
{
    int a1[3] = {1,2,3};
    print(a1, 3);
    nextPermutation(a1, 3);
    print(a1, 3);
    nextPermutation(a1, 3);
    print(a1, 3);
    nextPermutation(a1, 3);
    print(a1, 3);
    nextPermutation(a1, 3);
    print(a1, 3);
    nextPermutation(a1, 3);
    print(a1, 3);
}
