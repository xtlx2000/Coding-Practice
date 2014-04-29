#include <iostream>
using namespace std;

//��Ŀ����һ�Ҵ����װ����ΪboatMax,������5�������в�ͬ�Ĵ�С��������һ��װ�ط�����ʹ�����Ҵ���װ���������Ƕ���?
//input
int w[5] = {3,5,4,3,2};
int num = 5;
int boatMax = 9;


int maxLoadNum;
int currLoadNum;
int maxLoad(int level)
{
    //1 leaf node
    if(level >= num){

        if(currLoadNum > maxLoadNum){
            maxLoadNum = currLoadNum;
        }

        //3 return max
        return maxLoadNum;
    }

    //2 nonleaf node
    //2.1 case 0
    //2.1.1 set
    //2.1.2 recursion
    maxLoad(level+1);
    //2.1.3 repeal

    //2.2 case 1
    if(currLoadNum + w[level] <= boatMax){
        //2.2.1 set
        currLoadNum += w[level];
        //2.2.2 recursion
        maxLoad(level+1);
        //2.2.3 repeal
        currLoadNum -= w[level];
    }

    //3 return max
    return maxLoadNum;
}


int main()
{
    cout <<maxLoad(0)<<endl;
}





