#include <iostream>
#include <vector>
using namespace std;

//phone letter
string table[] = {
    "",//0
    "",//1
    "abc",//2
    "def",//3
    "ghi",//4
    "jkl",//5
    "mno",//6
    "pqrs",//7
    "tuv",//8
    "wxyz"//9
};


string curStr;
vector<string> result;
void letterCombination(string str, int step)
{
    //1 leaf node
    if(step >= str.size()){
        result.push_back(curStr);
        //3
        return;
    }

    //2 nonleaf node
    int tmpNumber = (str[step] - '0');
    string tmpString = table[tmpNumber];

    for(int i = 0; i < tmpString.size(); i++){
        //2.1 set
        string saveOld = curStr;
        string tmpStr(1, tmpString[i]);
        curStr += tmpStr;
        //2.2 recursion
        letterCombination(str, step+1);
        //2.3 repeal
        curStr = saveOld;
    }

    //3
    return;
}

int main()
{
    string str = "234";

    letterCombination(str, 0);

    for(vector<string>::iterator iter = result.begin();
        iter != result.end();
        iter++
    ){
        cout <<*iter<<endl;
    }

}
