#include <iostream>
#include <vector>
using namespace std;

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

string curStr;
vector<string> result;

void permutation(string str, int step)
{
    //1 leaf node
    if(step >= str.size()){

        //5 drop the replications
        int found = false;
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
    for(int i = step; i < str.size(); i++){
        //2.1set
        swap(&str[i], &str[step]);
        string tmp(1, str[step]);
        string saveold = curStr;
        curStr += tmp;

        //2.2recursion
        permutation(str, step+1);

        //2.3repeal
        swap(&str[i], &str[step]);
        curStr = saveold;
    }
}


int main()
{
    string str = "112";
    permutation(str, 0);
    for(vector<string>::iterator iter = result.begin();
        iter != result.end();
        iter++
        ){

        cout <<*iter<<endl;
    }
}
