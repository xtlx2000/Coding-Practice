#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int maxValuefunc(int step);

int v[5] = {4,3,2,1,5};
int part[5] = {2,2,3,4,1};
int num = 5;

//使用全局变量消除递归参数
int curMax;
int finalMax;

int main()
{
    cout <<maxValuefunc(0)<<endl;
}


int maxValuefunc(int step)
{
    //1 leaf-node: end
    if(step >= num){

        if(curMax > finalMax){
            finalMax = curMax;
        }

        return finalMax;
    }

    //2 nonleaf-node: deal detail
    //2.1 traver a[t..n]
    for(int i = step; i < num; i++){
        //2.1.1 set
        swap(&v[i], &v[step]);

        if(step % 4 == 0){
            curMax += (v[step] + part[step]);
        }else if(step % 4 == 1){
            curMax += (v[step] - part[step]);
        }else if(step % 4 == 2){
            curMax += (v[step] * part[step]);
        }else if(step % 4 == 3){
            curMax += (v[step] / part[step]);
        }

        //2.1.2 recursion
        maxValuefunc(step+1);

        //2.1.3 repeal
        if(step % 4 == 0){
            curMax -= (v[step] + part[step]);
        }else if(step % 4 == 1){
            curMax -= (v[step] - part[step]);
        }else if(step % 4 == 2){
            curMax -= (v[step] * part[step]);
        }else if(step % 4 == 3){
            curMax -= (v[step] / part[step]);
        }

        swap(&v[i], &v[step]);
    }

    //3 return final value;
    return finalMax;
}
