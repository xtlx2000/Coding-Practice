#include <iostream>
#incldue <stack>
#include <algorithm>
using namespace std;

//спринй

struct HeightAndIndex
{
    int height;
    int index;
};

int largestRectangle(int *a, int num);

int main()
{
    int a[6] = {2,1,5,6,2,3};
    cout <<largestRectangle(a, 6) << endl;
}


int largestRectangle(int *a, int num)
{
    stack<HeightAndIndex> stack_;

    HeightAndIndex tmp;
    tmp.height = a[0];
    tmp.index = 0;
    stack_.push(tmp);

    for(int i = 1; i < num; i++){
        tmp = stack.top();
        if(a[i] > tmp.height){
            tmp.height = a[i];
            tmp.index = i;
            stack_.push(tmp);
        }else if(a[i] == tmp.height){
            //ignore
        }else if(a[i] < tmp.height){
            stack_.pop();
        }
    }
}
