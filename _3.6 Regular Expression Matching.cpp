#include <iostream>
using namespace std;

bool isMatch(const char *s, const char *p);

int main()
{
    string str= "aa";
    string substr = "a*";
    cout <<isMatch(str.c_str(), substr.c_str())<<endl;
}
