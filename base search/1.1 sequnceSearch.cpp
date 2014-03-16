#include <iostream>
using namespace std;

int sequnceSearch(int *a, int num, int key)
{
    for(int i = 0; i <= num; i++){
        if(a[i] == key){
            return i;
        }
    }
    return -1;
}

int main()
{
    int a[9] = {7,5,4,2,17,9,3,5,0};
    cout <<sequnceSearch(a, 9, 2)<<endl;
}
