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


int main()
{
    string phone, style;
    cin >> phone;//13688044106
    cin >> style;//3-4-4

    for(int i = 0; i < style.size(); i++){
        if(style[i] == '-'){
            style[i] = ' ';
        }
    }

    //string cutting
    istringstream sin1(style);
    vector<string> v1;
    string x1;
    while(sin1 >> x1){
        v1.push_back(x1);
        cout <<x1<<endl;
    }

    //string cutting and to int
    istringstream sin2(style);
    vector<int> v2;
    int x2;
    while(sin2 >> x2){
        v2.push_back(x2);
        cout <<x2 <<endl;
    }

}
