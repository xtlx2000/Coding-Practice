#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <sstream>
#include <bitset>
#include <numeric>
#include <climits>
#include <string>
#include <cctype>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#define maxl 1000000000
using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

bool deletechar(string &str, int index);

int main()
{
    bool isValid = true;
    string str;
    string result;

    cin >> str;
    std::sort(str.begin(), str.end());
    //cout <<str<<endl;

    for(int i = 0; i < str.size(); i++){

        if((str[i]>= '0' && str[i] <= '9')
           ||(str[i] >= 'a' && str[i] <= 'z')
           ){
            //OK
        }else{
            isValid = false;
            break;
        }
    }

    if(!isValid){
        cout <<"<invalid input string>"<<endl;
        return 0;
    }


    while(str.size()){
        char prev;
        for(int i = 0, prev = '.'; i < str.size(); i++){

            char tmp = str[i];
            //cout <<"tmp = str["<<i<<"]="<<tmp;


            if(tmp != prev){
                //cout <<"   prev = "<<prev<<endl;
                deletechar(str, i);
                string tmpresult(1, tmp);
                result += tmpresult;
                prev = tmp;
                i--;

            }else{
                //cout <<"equal"<<endl;
                continue;
            }
        }

    }
    cout <<result<<endl;
}


bool deletechar(string &str, int index)
{
    string prev = str.substr(0, index);
    string post = str.substr(index+1);

    str = prev+post;

    return true;
}
