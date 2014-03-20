#include <iostream>
#include <vector>
using namespace std;

//dfs
vector<string> result;
string curStr;
void subsets(string str, int step)
{
    //1 leaf node
    if(step >= str.size()){

        bool found = false;

        //5 drop the replications
        for(vector<string>::iterator iter = result.begin();
            iter != result.end();
            iter++){

            if(*iter == curStr){
                found = true;
            }
        }

        if(found){
        }else{
            result.push_back(curStr);

        }

        //3
        return;
    }

    //2 nonleaf node
    //2.1 case 0
    //2.1.1 set
    //2.1.2 recursion
    subsets(str, step+1);
    //2.1.3 repeal

    //2,2 case 1
    //2.2.1 set
    string saveold = curStr;
    string tmp(1, str[step]);
    curStr += tmp;
    //2.2.2 recursion
    subsets(str, step+1);
    //2.2.3 repeal
    curStr = saveold;

    //3
    return;
}


int main()
{
    string a = "122";
    subsets(a, 0);

    for(vector<string>::iterator iter = result.begin();
        iter != result.end();
        iter++){

        cout <<*iter<<endl;
    }
}
