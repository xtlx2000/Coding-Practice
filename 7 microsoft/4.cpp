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

int comparestr(string &str1, string &str2)
{
    int total_words = 0;
    int not_words = 0;
    int right_words = 0;
    //string cutting
    istringstream sin1(str1);
    string x1;
    istringstream sin2(str2);
    string x2;
    while(sin1 >> x1){

        sin2 >> x2;

        total_words++;

        if(x1 == x2){
            right_words++;
        }else{
            not_words++;
        }
    }

    return not_words;
}

int main()
{
    vector<string> dict;
    int num[5] = {0};
    for(int i = 0; i < 5; i++){
        char buffer[256];
        memset(buffer, 0, 256);
        string tmp;
        cin.getline(buffer, 256);
        tmp = buffer;

        if(i == 0){
            dict.push_back(tmp);
        }else{

            for(int i = 0; i < dict.size(); i++){

                int not_words = comparestr(dict[i], tmp);
                if(not_words == 1){
                    num[i]++;
                }else{
                    dict.push_back(tmp);
                }
            }
        }
    }

    int maxnum = 0;
    for(int i = 0; i < 5; i++){
        if(num[i] > maxnum){
            maxnum = num[i];
        }
    }

    return maxnum;
}


