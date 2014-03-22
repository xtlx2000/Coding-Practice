#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstddef>
#include <queue>
using namespace std;


string cur;
string X;
int num = 0;


bool cutting()
{
    int pos = cur.find_first_of("?");
    if(pos == std::string::npos){
        return true;
    }

    string prefix_cur = cur.substr(0, pos);
    string prefix_X = X.substr(0, pos);

    if(prefix_cur < prefix_X){
        return false;
    }
    return true;
}


int func()
{
    //1 leaf node
    int pos = cur.find_first_of("?");
    if(pos == std::string::npos){

        if(cur > X){
            //cout <<"cur="<<cur<<endl;
            //cout <<"X="<<X<<endl;
            num++;
        }

        //3 return
        return num;
    }

    //2 nonleaf node
    for(int i = 0; i < 10; i++){
        //set
        string old = cur;
        cur[pos] = '0' + i;
        //recursion
        //cutting condition
        if(cutting()){
            func();
        }
        //repeal
        cur = old;
    }

    //3 return
    return num;
}

int tongpeifu()
{
    while(1){
        cin >> cur;
        cin >> X;

        cout <<func()<<endl;
        num = 0;
    }
}

int main()
{
    tongpeifu();
}
