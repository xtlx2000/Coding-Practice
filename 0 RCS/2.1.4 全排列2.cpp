#include <iostream>
#include <vector>
using namespace std;

void swap(string &str, int i, int j)
{
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

vector<string> result;

int Perm(string str, string prefix)
{
    if(str.size() == 1){
        result.push_back(prefix+str);
    }

    for(int i = 0; i < str.size(); i++){
        string tmpStr = str;
        swap(tmpStr, 0, i);

        string prefix_(1, tmpStr[0]);
        string prefix__ = prefix + prefix_;

        string substr_ = tmpStr.substr(1);

        Perm(substr_, prefix__);
    }
}

int main()
{
    string str = "1234";

    Perm(str, "");
    for(vector<string>::iterator iter = result.begin();
        iter != result.end();
        iter++
        ){

        cout <<*iter<<endl;
    }
}
