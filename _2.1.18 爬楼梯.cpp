#include <iostream>
using namespace std;

/*
 * 设f(i)为从0到i阶的走路方法数量
 * 每次都有2种选择：从第i阶走，要么走1阶到达(i+1)，要么走2阶到达(i+2)，
 * 当到达n时候，有可能是从n-1到达，或者是从n-2到达，递归之，得：
 *          f(n) = f(n-1) + f(n-2)，得出这是个fanbonichi数列
 */

//递归,时间复杂度O(2^n)
int walk1(int n)
{
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    return walk1(n-1) + walk1(n-2);
}

//迭代：利用迭代求fanbonachi数列
//f(n) = f(n-1) + f(n-2)
//时间复杂度O(n)
int walk2(int n)
{
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }

    int first = 1;
    int second = 2;
    int result = 0;
    for(int i = 3; i <= n; i++){
         result = first + second;
         first = second;
         second = result;
    }
    return result;
}


int main()
{
    cout <<walk1(40)<<endl;
    cout <<walk2(40)<<endl;
}
