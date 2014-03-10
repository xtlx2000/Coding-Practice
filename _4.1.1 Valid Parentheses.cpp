#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool isValid(string str);

int main()
{
    string str = "(()())";
    cout <<isValid(str)<<endl;
}

bool isValid(string str)
{
    stack<char> stackString;
    int i = 0;
    for(int i = 0; i < str.size(); i++){
        if(   (str[i] == '(')
            ||(str[i] == '[')
            ||(str[i] == '{')
           ){

           stackString.push(str[i]);
        }else{

            char tmp = stackString.top();
            stackString.pop();
            if(
                    (str[i] == ')' && tmp == '(')
                ||  (str[i] == ']' && tmp == '[')
                ||  (str[i] == '}' && tmp == '{')
              ){
                //OK
            }else{
                return false;
            }
        }
    }

    if(stackString.empty()){
        return true;
    }else{
        return false;
    }
}
