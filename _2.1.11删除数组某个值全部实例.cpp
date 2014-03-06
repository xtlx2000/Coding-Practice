#include <iostream>
using namespace std;

int function(int *a, int num, int target);

int main()
{
    int a[8] = {5,3,56,2,3,2,3,9};
    cout <<function(a, 8, 2)<<endl;
}

int function(int *a, int num, int target)
{
    int index = 0;
    for(int i = 0; i < num; i++){
        if(a[i] != target){
            a[index] = a[i];
            index++;
        }
    }

    return index;
}
