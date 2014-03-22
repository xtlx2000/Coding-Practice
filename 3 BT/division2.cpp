#include <iostream>
#include <set>
using namespace std;

//��1��9λ����ÿλ��1-9����Ҳ����ظ�����ǰ2λ�ܱ�2������ǰ3λ�ܱ�3����...ǰ9λ�ܱ�9����

int num = 9;
//ʹ��ȫ�ֱ��������ݹ����
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

