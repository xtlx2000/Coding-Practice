class Solution {
    //input
    std::string mStr;
    // data
    std::string mPostfix;
    std::string mCurrIP;
    std::vector<std::string> mResult;

    void helper(int level)
    {
        if (level > 4)
        {
            mResult.push_back(mCurrIP);
            return;
        }

        for (size_t i = 0; i < mPostfix.size()-1; ++i)
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
                break;
            }
            helper(level+1);
            //pop
            mPostfix = oldPostfix;
            mCurrIP = oldCurrIP;
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        mStr = s;
        mPostfix = mStr;
        helper(0);
        return mResult;
    }
};