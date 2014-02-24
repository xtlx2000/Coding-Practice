#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Test {
public:
    static int howmany (int   N,int   K,int   B0,int   B1,int   B2,int   B3)
    {

        int total = 0;
        vector<int> a(N);
        vector<int> b(4);

        b[0] = B0;
        b[1] = B1;
        b[2] = B2;
        b[3] = B3;

        for(int i = 0; i < N; i++){
            a[i] = i;
        }

        sort(a.begin(), a.end());

        do{

            if(
               (a[a[b[0]]]*b[0]+a[a[b[1]]]*b[1]+a[a[b[2]]]*b[2]+a[a[b[3]]]*b[3])%N==K
               ){
                total++;
            }

        }while(next_permutation(a.begin(), a.end()));

        return total;

    }
};
//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{
    cout<<Test::howmany(10,2,2,2,2,2)<<endl;
}
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。
