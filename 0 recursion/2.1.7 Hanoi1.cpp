#include <iostream>
using namespace std;

int Hanoi(int n)
{
    if(n == 1){
        return 1;
    }

    int num = 0;
    num += Hanoi(n-1);
    num++;
    num += Hanoi(n-1);

    return num;
}

int main()
{
    cout <<Hanoi(1)<<endl;
    cout <<Hanoi(2)<<endl;
    cout <<Hanoi(3)<<endl;
    cout <<Hanoi(4)<<endl;
}
