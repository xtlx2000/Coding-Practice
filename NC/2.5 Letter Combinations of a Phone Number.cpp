#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//input
//卡壳1：不知道vector<>怎么初始化
string keyboard[10] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

string digits = "23";

//output
string currStr;

void phoneNumber(int level)
{
    if(level >= digits.size()){

        cout <<currStr<<endl;

        return;
    }

    for(int i = 0; i < keyboard[digits[level]-'0'].size(); i++){

        //set
        string oldStr = currStr;
        currStr += keyboard[digits[level]-'0'][i];
        //recursion
        phoneNumber(level+1);
        //repeal
        currStr = oldStr;
    }
}

int main()
{
    phoneNumber(0);
}





