#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 1¡¢¼Ð±Æ·¨
 */
struct three
{
  int num[3];
};
void function1(int *a, int num, int target);

/* 2¡¢Î»Í¼·¨
 */
void function2(int *a, int num, int target);

int main()
{
    int a[6] = {-1, 0, 1, 2, -1, -4};
    function1(a, 6, 0);
    function2(a, 6, 0);
}


void function1(int *a, int num, int target)
{
    vector<int> sortedArray(num);
    vector<struct three> result;

    for(int i = 0; i < num; i++){
        sortedArray[i] = a[i];
    }

    sort(sortedArray.begin(), sortedArray.end());
    for(int i = 0; i < num; i++){
        cout <<sortedArray[i]<<endl;
    }
    for(int i = 0; i < num; i++){
        int j = i+1;
        int k = num-1;

        while(j < k){
            int sum = sortedArray[i]+sortedArray[j]+sortedArray[k];

            if(sum == target){
                three tmpresult;
                tmpresult.num[0] = sortedArray[i];
                tmpresult.num[1] = sortedArray[j];
                tmpresult.num[2] = sortedArray[k];
                result.push_back(tmpresult);

            }else if(sum > target){
                k--;

            }else if(sum < target){
                j++;
            }
        }
    }

    sort(result.begin(), result.end());
    unique(result.begin(), result.end());
    result.erase(result.begin(), result.end());

    for(vector<struct three>::iterator iter = result.begin();
        iter != result.end();
        iter++){

        cout <<"{"<<(*iter).num[0]<<" "<<(*iter).num[1]<<" "<<(*iter).num[2]<<"}"<<endl;
    }
}

void function2(int *a, int num, int target)
{

}
