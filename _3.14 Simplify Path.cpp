#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string simplifyPath(string longPath)
{
    string str = longPath;
    stack<string> stackString;
    string result = "/";
    size_t pos = 0;

    while(str.size() > 0){

        cout <<str.size()<<endl;
        string tmpDir;
        pos = str.find('/');
        if(pos == string::npos){
            pos = str.size();
            str = "";
            tmpDir = str;
        }else{
            str = str.substr(pos+1);
            tmpDir = str.substr(0, pos);
        }

        cout <<"tmpDir="<<tmpDir<<endl;
        cout <<"str="<<str<<endl;

        if(tmpDir == "."){
            continue;
        }else if(tmpDir == ".."){
            if(!stackString.empty()){
                stackString.pop();
            }
        }else{
            stackString.push(tmpDir);
        }
    }

    stack<string> tmpStack;
    while(!stackString.empty()){
        string tmpStr = stackString.top();
        stackString.pop();
        tmpStack.push(tmpStr);
    }

    while(!tmpStack.empty()){
        result += tmpStack.top();
        tmpStack.pop();
        result += "/";
    }

    result = result.substr(0, result.size()-1);

    return result;
}

int main()
{
    string path = "/a/b/c/hehe";
    cout <<simplifyPath(path)<<endl;
}
