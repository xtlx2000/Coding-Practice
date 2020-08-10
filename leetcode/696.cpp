class Solution {
    std::string mStr;
    int mCount;
    void findResults(size_t idx)
    {
        size_t left = idx;
        size_t right = idx+1;
        while (true)
        {
            if (left < 0 || left >= mStr.size() 
             || right < 0 || right >= mStr.size())
            {
                 break;
            }
            if (mStr[left] != mStr[idx] || mStr[right] != mStr[idx+1])
            {
                break;
            }
            mCount++;
            left--;
            right++;
        }
    }
public:
    int countBinarySubstrings(string s) {
        mStr = s;
        mCount = 0;
        for (size_t i = 0; i < mStr.size()-1; ++i)
        {
            if (mStr[i] == mStr[i+1])
            {
                continue;
            }
            else{
                findResults(i);
            }
        }
        return mCount;
    }
};