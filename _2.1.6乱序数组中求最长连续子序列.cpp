#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

/* 1、先排序，之后用一个游标就很容易求出，时间复杂度O(nlogn),空间复杂度O(1)
 */

/* 2、用位图(实现可以用unordered_map代替),时间复杂度O(n)，空间复杂度O(..)
 */

int function(int *a, int num);

int main()
{
    int a[6] = {100, 4, 200, 1, 3, 2};
    cout <<function(a, 6)<<endl;
}

int function(int *a, int num)
{
    int maxNum = 0;
    int maxConsecutiveLength = 0;
    int curLength = 0;
    unordered_map<int, bool> hashTable;
    //找最大一个数
    for(int i = 0; i < num; i++){
        if(a[i] > maxNum){
            maxNum = a[i];
        }
    }

    for(int i = 0; i < maxNum; i++){
        hashTable[i] = false;
    }
    for(int i = 0; i < num; i++){
        hashTable[a[i]] = true;
    }

    for(int i = 0; i < maxNum; i++){
        if(hashTable[i]){
            curLength++;
        }else{
            if(curLength > maxConsecutiveLength){
                maxConsecutiveLength = curLength;
            }
            curLength = 0;
        }
    }

    return maxConsecutiveLength;
}
