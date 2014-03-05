#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
 * input: a[]={2,7,11,15}, target=9
 * output:index1=0, index2=1
 */

/*
 * 1、先排序，用2个变量，用a来遍历，每个a在用b来夹逼，时间复杂度O(n^2)
 */

/*
 * 2、位图法
 */

//位图法
void function(int *a, int num, int target);

int main()
{
    int a[4] = {2,7,11,15};
    function(a, 4, 9);
}

void function(int *a, int num, int target)
{
    unordered_map<int, int> hashTable;
    vector<int> result;

    for(int i = 0; i < num; i++){
        hashTable[a[i]] = i;
    }

    for(int i = 0; i < num; i++){
        int subtructResult = target - a[i];
        if(hashTable[subtructResult]){
            result.push_back(i);
            result.push_back(hashTable[subtructResult]);
        }
    }


    for(vector<int>::iterator iter = result.begin();
        iter != result.end();
        iter++){

        cout <<iter<<" ";
    }
    cout <<endl;
}
