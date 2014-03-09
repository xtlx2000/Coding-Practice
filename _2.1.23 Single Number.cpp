#include <iostream>
using namespace std;

//1 ���������ҳ���  O(nlogn)  O(1)
//2 λͼ              O(n)      O(x)
//3 ^                 O(n)      O(1)


int function(int *a, int num);

int main()
{
    int a[5] = {2,2,5,4,5};
    cout <<function(a, 5)<<endl;
}


int function(int *a, int num)
{
    int single = 0;
    for(int i = 0; i < num; i++){
        single ^= a[i];
    }

    return single;
}
