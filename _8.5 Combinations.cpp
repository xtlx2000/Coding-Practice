#include <iostream>
#include <vector>
using namespace std;

string curStr;
int charNum;
vector<string> result;
void combination(string str, int step)
{
    //1 leaf node
    if(step >= str.size()){

        //5 cutting
        if(charNum == 2){
            result.push_back(curStr);
        }
        //3 return
        return;
    }

    //2 nonleaf node
    //2.1 case 0
    //2.1.1 set
    //2.1.2 recursion
    combination(str, step+1);
    //2.1.3 repeal

    //2.2 case 1
    //2.2.1 set
    string saveOld = curStr;
    string tmpChar(1, str[step]);
    curStr += tmpChar;
    charNum++;
    //2.2.2 recursion
    //4 cutting condition
    if(charNum > 2){
        //cutting condition
    }else{
        combination(str, step+1);
    }
    //2.2.3 repeal
    curStr = saveOld;
    charNum--;

    //3 return
    return;
}

int main()
{
    string str = "123";
    combination(str, 0);
    for(vector<string>::iterator iter = result.begin();
        iter != result.end();
        iter++
        ){

        cout <<*iter<<endl;
    }
}
