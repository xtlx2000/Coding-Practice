#include <iostream>
#include <set>
using namespace std;

//找1个9位数，每位由1-9组成且不能重复，且前2位能被2整除，前3位能被3整除...前9位能被9整除

int num = 9;
//使用全局变量消除递归参数
bool found = false;
set<int> numSet;
int cur;
int final;



int shijizhi(int shi, int i_)
{
    int num = 1;
    for(int i = 0; i < shi; i++){
        num *= 10;
    }

    num *= i_;
    return num;
}
int findNum(int step)
{
    //1 leaf node
    if(step > num){
        int tmp = cur;
        for(int chushu = 9; chushu > 1; chushu--){
            if(tmp % chushu == 0){
                found = true;
            }else{
                found = false;
                break;
            }
            tmp /= 10;
        }

        if(found){
            final = cur;
        }

        return final;
    }

    //2 nonleaf node
    for(int i = 1; i <= 9; i++){
        //duplicate check
        if(numSet.find(i) == numSet.end()){
            //OK
        }else{
            continue;
        }
        //set
        int old = cur;
        cur += shijizhi(step-1, i);
        numSet.insert(i);

        //recursion
        findNum(step+1);
        //repeal
        cur = old;
        numSet.erase(i);
    }

    return final;
}

int main()
{
    findNum(1);
    if(final){
        cout <<final<<endl;
    }else{
        cout <<"not found"<<endl;
    }
}

