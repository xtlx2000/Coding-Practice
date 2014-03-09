#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
    bool isPalindrome(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int start = 0;
        int last = s.size() - 1;

        while(start < last){
            if(s[start] < 'a' && s[start] > 'z'){
                start++;
            }
            if(s[last] < 'a' && s[last] > 'z' ){
                last++;
            }

            if(s[start] == s[last]){
                start++;
                last--;
            }else{
                return false;
            }
        }

        return true;
    }
};

int main()
{
    string str1 = "A man, a plan, a canal: Panama";
    string str2 = "aabcbaa";
    Solution s;
    cout <<s.isPalindrome(str1) << endl;
    cout <<s.isPalindrome(str2) << endl;
}
