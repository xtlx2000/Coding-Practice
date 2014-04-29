#include <iostream>
using namespace std;

//题目：先有一个数字集合v，找出他们的一个排列，使得M(v[i] ops part[i])的值最大？
//input
int v[5] = {4,3,2,1,5};
int part[5] = {2,2,3,4,1};
int num = 5;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int maxValueNum;
int currValueNum;
int maxValue(int level)
{
    //2.1 leaf node
    if(level >= num){

        if(currValueNum > maxValueNum){
            maxValueNum  = currValueNum;
        }

        return maxValueNum;
    }

    //2.2 nonleaf node
    for(int i = level; i < num; i++){

        //2.2.1 swap and set
        swap(&v[i], &v[level]);
        if(i % 4 == 0){
            currValueNum += v[i]+part[i];
        }else if (i % 4 == 1){
            currValueNum += v[i]-part[i];
        }else if (i % 4 == 2){
            currValueNum += v[i]*part[i];
        }else if (i % 4 == 3){
            currValueNum += v[i]/part[i];
        }
        //2.2.2 recursion
        maxValue(level+1);
        //2.2.3 repeal and swap
        if(i % 4 == 0){
            currValueNum -= v[i]+part[i];
        }else if (i % 4 == 1){
            currValueNum -= v[i]-part[i];
        }else if (i % 4 == 2){
            currValueNum -= v[i]*part[i];
        }else if (i % 4 == 3){
            currValueNum -= v[i]/part[i];
        }
        swap(&v[i], &v[level]);
    }

    return maxValueNum;
}

int main()
{
    cout <<maxValue(0)<<endl;
}





