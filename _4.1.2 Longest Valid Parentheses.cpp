#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int longestValidParentheses(string str);

int main()
{
    cout <<longestValidParentheses("((()()(()))")<<endl;
}

int longestValidParentheses(string str)
{
    stack<char> stackChar;
    int longest = 0;
    int tmpLong = 0;
    bool sequence = false;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '('){
            stackChar.push('(');
        }else if(str[i] == ')'){

            if(stackChar.empty()){
                sequence = false;
                tmpLong = 0;
            }else{
                stackChar.pop();
                tmpLong += 2;
                longest = max(tmpLong, longest);
            }
        }
    }

    return longest;
}
