#include <string>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


class Solution
{
public:
    int longestValidParentheses(string s) {
        //show your code here
        int max_len = 0, last = -1;
        stack<int > lefts;

        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                lefts.push(i);
            }else{
                if(lefts.empty()){
                    last = i;
                }else{
                    lefts.pop();
                    if(lefts.empty()){
                        max_len = max(max_len, i-last);
                    }else{
                        max_len = max(max_len, i-lefts.top());
                    }
                }
            }
        }
        return max_len;

    }

};


//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{
    //..
    Solution s;
    cout <<s.longestValidParentheses("(()()()")<<endl;
}
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。
