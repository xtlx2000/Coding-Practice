#include <iostream>
using namespace std;

int partition(int n, int limit)
{
    if(n == 0){
        return 1;
    }

    int num = 0;
    for(int i = n; i > 0; i--){

        if(i > limit){
            continue;
        }

        num += partition(n-i, i);
    }

    return num;
}

int main()
{
    cout << partition(1, 1) <<endl;
    cout << partition(2, 2) <<endl;
    cout << partition(3, 3) <<endl;
    cout << partition(4, 4) <<endl;
    cout << partition(5, 5) <<endl;
}
