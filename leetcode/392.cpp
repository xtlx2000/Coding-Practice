class Solution {
    public:
        bool isSubsequence(string s, string t) {
            size_t i = 0;
            size_t j = 0;

            while (j <= t.size())
            {
                if (i == s.size())
                {
                    return true;
                }

                if (s[i] == t[j])
                {
                    ++i;
                }
                ++j;
            }

            return false;
        }
};
