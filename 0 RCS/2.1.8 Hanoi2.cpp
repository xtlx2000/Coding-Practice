#include <iostream>
using namespace std;

int Hanoi(int n, string a, string b, string c)
{
    if(n == 1){
        cout <<n<<"-th: "<<a<<"->"<<b<<endl;
        return 1;
    }

    int num = 0;
    num += Hanoi(n-1, a, c, b);
    num++;cout <<n<<"-th: "<<a<<"->"<<b<<endl;
    num += Hanoi(n-1, c, b, a);

    return num;
}

int main()
{
    Hanoi(1, "a", "b", "c");cout <<endl;
    Hanoi(2, "a", "b", "c");cout <<endl;
    Hanoi(3, "a", "b", "c");cout <<endl;
    Hanoi(4, "a", "b", "c");cout <<endl;
}
