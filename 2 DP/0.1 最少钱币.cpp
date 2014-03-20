//如果我们有面值为1元、3元、5元的硬币若干枚，如何用最少的硬币凑够11元？

#include <iostream>
#include <algorithm>
using namespace std;

/* (1) 找出“状态”：d(i) = j  凑够i元钱最少需要j个硬币
 * (2) 找出各个状态，从中找出大状态依赖消状态的关系：
   d(0) = 0
 * d(1) = 1 + d(0) = 1+0=1
 * d(2) = 1 + d(1) = 1+1=2
 * d(3) = min{1+d(2), 3+d(0)}
 * d(4) = min{1+d(3), 3+d(1)}
 * d(5) = min{1+d(4), 3+d(2), 5+d(0)}
 * ...
 * (3) 总结出大状态依赖消状态的关系，建立递推关系式：
 * d(i) = min{1+d(i-x)} 其中x为小于等于i的钱币面值
 * (4) code
 * (5) check
 */
#define MAXSIZE 65535
int function(int a[], int n, int num);
int main()
{
    int a[3] = {1,3,5};
    int num = 11;

    cout << function(a, 3, num) <<endl;
}

int function(int a[], int n, int num)
{
    //1 准备备忘录
    int minTable[num+1];
    for(int i = 0; i < num; i++){
        minTable[i] = MAXSIZE;
    }

    //2 循环从小到大算出备忘录
    for(int i = 0; i <= num; i++){
        //2.1 定义初始状态
        if(i == 0){
            minTable[i] = 0;
        }
        //2.2 递推关系式
        for(int j = 0; j < n; j++){
            if(a[j] <= i){
                minTable[i] = min(
                                (minTable[i]),
                                (1 + minTable[i-a[j]])
                             );
            }
        }
    }
    //3 结束
    return minTable[num];
}
