#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 2) return n;

        int prevNum = A[0]; //记录当前重复的数字
        int prevCnt = 1;    //记录当前数字出现的次数
        int curIdx = 1;     /*
                             * 记录下次要更正的位置下标，
                             * 即A[0]到A[curIdx-1]是处理完毕的，
                             * 且最终curIdx是处理完毕后的数组长度
                             */
        for(int i = 1; i < n; ++i)
        {
            //A[i]是个重复数
            if(A[i] == prevNum)
            {
                //A[i]重复了2次以上
                if(prevCnt == 2){
                    continue;//数字出现2次以上，没有需要修改的变量

                //A[i]重复了1次
                }else{
                    A[curIdx] = A[i];//因为只重复了1次，后面的数字一定要要
                    curIdx++;//更新下次写的index
                    prevCnt++;//此数字出现的次数加1
                }
            //A[i]第一次出现
            }else{
                A[curIdx] = A[i];//第一次出现的数是一定要要的
                curIdx++;//更新下次写的index
                prevNum = A[i];//更新当前重复的数字
                prevCnt = 1;//更新当前数字出现的次数
            }
        }
        return curIdx;
    }
};

int main()
{
    int a[10] = {1,1,1,1,2,2,3,3,3,3};
    Solution s;
    cout <<s.removeDuplicates(a, 10)<<endl;

    return 0;
}
