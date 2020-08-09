#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    //input
    std::string mStr;
    // data
    std::string mPostfix;
    std::string mCurrIP;
    std::vector<std::string> mResult;

    void helper(int level)
    {
        if (level == 3)
        {
            mResult.push_back(mCurrIP + "." + mPostfix);
            return;
        }

        for (size_t i = 1; i < mPostfix.size(); ++i)
        {
            //push
            std::string oldPostfix = mPostfix;
            std::string oldCurrIP = mCurrIP;
            //swap
            std::string prefix = mPostfix.substr(0, i);
            if (stoi(prefix) > 255)
            {
                break;
            }
            mPostfix = mPostfix.substr(i);
            mCurrIP += "." + prefix;
            //dfs
            if (level == 2 && stoi(mPostfix) > 255)
            {
                // continue
            }
            else
            {
                helper(level+1);
            }
            //pop
            mPostfix = oldPostfix;
            mCurrIP = oldCurrIP;
        }
    }

    void trimResult()
    {
        for (size_t i = 0; i < mResult.size(); ++i)
        {
            mResult[i] = mResult[i].substr(1);
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        mStr = s;
        mPostfix = mStr;
        helper(0);
        trimResult();
        return mResult;
    }
};

int main()
{
    std::string s = "19216811";
    Solution ss;
    vector<string> r = ss.restoreIpAddresses(s);
    for (int i = 0; i < r.size(); ++i)
    {
        std::cout <<r[i]<< std::endl;
    }
    return 0;
}
