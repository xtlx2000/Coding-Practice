#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//1標排
//2弇芞


//標排
#define INT_MAX  65535
int function(int *a, int num, int target)
{
    int result = 0;
    int min_gap = INT_MAX;

    vector<int> vec(num);
    for(int i = 0; i < num; i++){
        vec[i] = a[i];
    }

    sort(vec.begin(), vec.end());


    for(int i = 0; i < num; i++){
        int j = i+1;
        int k = num-1;

        while(j < k){
            int sum = vec[i]+vec[j]+vec[k];
            int gap = abs(sum - target);

            if(gap < min_gap){
                result = sum;
                min_gap = gap;
            }

            if(sum < target){
                j++;
            }else{
                k--;
            }
        }
    }

    return result;
}


int main()
{
    int a[] = {-1, 2, 1, -4};
    cout <<function(a, 4, 1)<<endl;
}
