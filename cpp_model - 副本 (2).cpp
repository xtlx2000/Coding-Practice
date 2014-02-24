#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct myclass {
  bool operator() (int i,int j) { return (i>j);}
} myobject;

int howMany(string &str)
{
    if(str.size() == 0){
        return 0;
    }else if(str.size() == 1){
        return 1;
    }

    string::iterator it;
    char cmp = str[0];
    int count = 0;

    for(int i = 0;i < str.size();i++)
    {
        if(cmp == str[i])
        {
            count++;
            str.erase(i,1);
            i--;
        }
    }

    return count;
}

int perfect(const string &s)
{
    string str = s;
    vector<int> charCounts;

    int count, i, j;
    int perfectNum = 0;

    transform(str.begin(), str.end(), str.begin(), ::toupper);

    do{
        count = howMany(str);
        charCounts.push_back(count);
    }while(count > 0);

    sort(charCounts.begin(), charCounts.end(), myobject);

    for(i=0,j=26;i<charCounts.size();i++,j--)
    {
        perfectNum=perfectNum+j*charCounts[i];
        //cout << charCounts[i] << " --- ";
    }


    //cout << endl;
    //cout << "perfect Num is " << perfectNum << endl;
    return perfectNum;
}

int main()
{
    cout << perfect("DAddfdafdfhjfaodnDFESSDF") << endl;
}
