#include <iostream>
using namespace std;

//eg: 5,3,4,8,6,7
/* (1)找出状态表达式：d(i) = j,前i个数中最长非降子序列长度为j
 * (2)根据状态表达式找出各个状态
 * d(0) = 0
 * d(1) = 1
 * d(2) = 3>=5 ? d(1)+1 : max{d(1), 1} = 1
 * d(3) = 4>=3 ? d(2)+1 : max{d(2), 1} = 2
 * d(4) = 8>=4 ? d(3)+1 : max{d(3), 1} = 3
 * ...
 * (3)根据各个状态找出大状态依赖小状态的递推关系
 *  d(i) = (A[i-1] >= A[i-2])? d(i-1)+1 : max{d(i-1), 1}
 * (4)coding
 * (5)check
 */

int function(int *a, int num);

int main()
{
    int a[6] = {5,3,4,8,6,7};
    cout <<function(a, 6)<<endl;
}

int function(int *a, int num)
{
    //1 准备备忘录
    int LongestTable[num+1];
    for(int i = 0; i < num+1; i++){
        LongestTable[i] = 0;
    }

    //2 初始化初始状态
    LongestTable[0] = 0;

    //3 表达式递推关系
    for(int i = 1; i < num+1; i++){
        LongestTable[i] = a[i-1] >= a[i-2] ?
                            (LongestTable[i-1] + 1) :
                            ( max(
                                  LongestTable[i-1],
                                  1
                                  )
                             );
    }
    //4 结束
    return LongestTable[num];
}
