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

int main()
{
    int number;
    cin >> number;

    for(int i = 0; i < number; i++){
        int N, M, K;
        cin >> N >> M >> K;

        string first;
        vector<string> dict;
        for(int i = 0; i < N; i++){
            first += "0";
        }
        for(int i = 0; i < M; i++){
            first += "1";
        }

        do {
            //cout <<first<<endl;
            dict.push_back(first);
        } while ( std::next_permutation(first.begin(), first.end()) );

        if(K > dict.size()){
            cout <<"Impossible"<<endl;
        }else{
            cout <<dict[K-1]<<endl;
        }
    }
}
