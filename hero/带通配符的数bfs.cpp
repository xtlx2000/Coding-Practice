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
string final;
queue<string> que;
int level;
int num;

void enQueue(string cur, string X)
{
    int pos = cur.find_first_of("?");
    if(pos == std::string::npos){

        if(cur > X){
            num++;
        }
    }else{
        que.push(cur);
    }
}

int func(string W, string X)
{
    cur = W;
    que.push("-1");

    while(1){

        int pos = cur.find_first_of("?");
        if(pos == std::string::npos){
            return num;
        }

        for(int i =0; i < 10; i++){
            cur = W;
            cur[pos] = i+'0';
            enQueue(cur, X);
        }

        cur = que.front();
        que.pop();

        if(cur == "-1" && que.empty()){
            return num;
        }else if(cur == "-1" && !que.empty()){
            //3 things
            level++;
            que.push("-1");
            cur = que.front();
            que.pop();
        }else if(cur != "-1"){
            //nothing to do
        }
    }
}

int tongpeifu()
{
    while(1){
        string W;
        cin >> W;
        string X;
        cin >> X;

        cout <<func(W, X)<<endl;
    }
}

int main()
{
    tongpeifu();
}
