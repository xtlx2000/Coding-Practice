#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

//卡壳1：这道题同样是子集树，但是0、1分别代表什么呢？比如str="abcba"，有5个元素，
//子集树的0、1想当然的代表每个数是取还是舍吗？根据题意不是元素的取舍，而是全部都要取，但
//重点是划分，因此要将每2个元素之间的间隔当做元素，1代表分割开，0代表不分割开，而5个元素
//有4个间隔，因此num的取值应该是4！要分析题意，教训！


//intput
string str = "abcba";


//output
int num = str.size()-1;
int lastPos;
vector<string> currPartition;
bool isPalindrome(string str)
{
    int mid;
    if(str.size() % 2 == 0){
        mid = str.size()/2;
    }else{
        mid = str.size()/2+1;
    }

    for(int i = 0; i < mid; i++){

        if(str[i] == str[str.size()-i-1]){
        }else{
            return false;
        }
    }

    return true;
}

void palindromePartition(int level)
{
    //卡壳2：一定要明白每次递归level的值是树的那一层，把树画下来，注明level！！
    if(level >= num){

        if(lastPos >= num){
            for(vector<string>::iterator iter = currPartition.begin();
                iter != currPartition.end();
                iter++){

                cout <<*iter<<",";
            }
            cout <<endl;
        }
        return;
    }

    //case 0
    //set
    //recursion
    palindromePartition(level+1);
    //repeal


    //case 1
    //卡壳3：没用str.substr()的用法
    string substr = str.substr(lastPos, level+1-lastPos);
    //cout <<lastPos<<"-"<<level+1<<"="<<substr<<endl;

    if(isPalindrome(substr) == true){
        //set
        int oldLastPos = lastPos;
        lastPos = level + 1;
        currPartition.push_back(substr);
        if(level == num - 1){
            substr = str[lastPos];
            currPartition.push_back(substr);
            lastPos += 1;
        }

        //recursion
        palindromePartition(level+1);

        //repeal
        if(level == num-1){
            currPartition.pop_back();
            lastPos -= 1;
        }
        currPartition.pop_back();
        lastPos = oldLastPos;


        return;

    }

}


int main()
{
    palindromePartition(0);
}
