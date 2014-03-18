#include <iostream>
using namespace std;

int partition(int n, int limit, string prefix)
{
    if(n == 0){
        cout <<prefix<<endl;
        return 1;
    }

    int num = 0;
    for(int i = n; i > 0; i--){

        if(i > limit){
            continue;
        }

        string cur(1, '0'+i);
        string prefix_ = prefix + "+" + cur;
        num += partition(n-i, i, prefix_);
    }

    return num;
}

int main()
{
    partition(1, 1, "");cout <<endl;
    partition(2, 2, "");cout <<endl;
    partition(3, 3, "");cout <<endl;
    partition(4, 4, "");cout <<endl;
    partition(5, 5, "");cout <<endl;
}
