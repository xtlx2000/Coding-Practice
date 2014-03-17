#include <iostream>
using namespace std;

int Perm(int n)
{
    if(n == 1){
        return 1;
    }

    return n*Perm(n-1);
}

int main()
{
    cout <<Perm(4)<<endl;
}
