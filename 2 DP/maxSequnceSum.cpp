#include <iostream>
#include <algorithm>
using namespace std;

int a[] = {-2,1,2,0,-9,10};
int num  =6;

int maxSum()
{
	int maxSumArr[num];
	maxSumArr[0] = a[0];
    int maxSumValue = maxSumArr[0];

	for(int i = 1; i < num; i++){

		maxSumArr[i] = max(
							(maxSumArr[i-1]+a[i]),
							(a[i])
						);
        if(maxSumArr[i] > maxSumValue){
            maxSumValue = maxSumArr[i];
        }
	}

    return maxSumValue;
}

int main()
{
    cout <<maxSum()<<endl;
}
