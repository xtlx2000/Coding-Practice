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

void func();

int main()
{
    for(;;){
        func();
    }
}

bool deletechar(string &str, int index)
{
    string prev = str.substr(0, index);
    string post = str.substr(index+1);

    str = prev+post;

    return true;
}


int inversion_num(string &str)
{
    int num = 0;
    for(int i = 0; i < str.size(); i++){

        for(int j = i+1; j < str.size(); j++){

            if(str[i] > str[j]){
                num++;
            }
        }
    }

    return num;
}


void func()
{
    string str;
    cin >>str;


    for(int i = 0; i < str.size(); i++){
        if(str[i] == ','){
            deletechar(str, i);
        }
    }
    //cout <<str<<endl;

    int min_inversion_num = inversion_num(str);

    //cout <<"--size = "<<str.size()<<endl;


    for(int i = 0; i < str.size(); i++){

        for(int j = i+1; j < str.size(); j++){

            //cout <<i<<"   "<<j<<endl;
            if(str[i]  <= str[j]){
                //
            }else{
                //set
                char tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;


                int tmp_inversion_num = inversion_num(str);
                if(tmp_inversion_num < min_inversion_num){
                    min_inversion_num = tmp_inversion_num;
                }


                //repeal
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }

        }
    }



    cout <<min_inversion_num<<endl;
}
