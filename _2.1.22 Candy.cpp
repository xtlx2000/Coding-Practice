#include <iostream>
using namespace std;

int function(int *a, int num);

int main()
{
    int a[8] = {3,2,1,2,3,2,1,3};

    cout <<function(a, 8)<<endl;
}

int function(int *a, int num)
{
    int results[num];

    for(int i = 0; i < num; i++){
        results[i] = 0;
    }

    int count = 1;
    for(int i = 1; i < num; i++){
        if(a[i-1] < a[i]){
            results[i] = max(
                       (count),
                       (results[i])
                       );
            count++;
        }else{
            count = 1;
        }
    }


    for(int i = 0; i < num; i++){
        cout <<results[i]<<" ";
    }
    cout <<endl;


    count = 1;
    for(int i = num-2; i >= 0; i--){
        if(a[i] > a[i+1]){
            results[i] = max(
                       (count),
                       (results[i])
                       );
            count++;
        }else{
            count = 1;
        }
    }

    for(int i = 0; i < num; i++){
        results[i]++;
    }

    int result = 0;
    for(int i = 0; i < num; i++){
        cout <<results[i]<<" ";
        result += results[i];
    }
    cout <<endl;


    return result;
}
