#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int> > mMatrix;
    vector<vector<int> > mMemo;

    int mLogestIncreasingPathNum;

    int mCurrIncreasingPathNum;
    int mLastValue;
    int mX;
    int mY;

    void helper()
    {
        // end conditon
        if ((mX < 0 || mX >= mMatrix.size())
            || (mY < 0 || mY >= mMatrix[0].size())
            || mMatrix[mX][mY] <= mLastValue)
        {
            if (mCurrIncreasingPathNum > mLogestIncreasingPathNum)
            {
                mLogestIncreasingPathNum = mCurrIncreasingPathNum;
            }
            return;
        }

        if (mMemo[mX][mY] != 0)
        {
            mCurrIncreasingPathNum += mMemo[mX][mY];
            if (mCurrIncreasingPathNum > mLogestIncreasingPathNum)
            {
                mLogestIncreasingPathNum = mCurrIncreasingPathNum;
            }
            mCurrIncreasingPathNum -= mMemo[mX][mY];
            return;
        }

        mCurrIncreasingPathNum++;
        int currLastValue = mLastValue;
        mLastValue = mMatrix[mX][mY];
        // case up
        mX--;
        helper();
        mX++;

        // case down
        mX++;
        helper();
        mX--;

        // case left
        mY--;
        helper();
        mY++;

        // case right
        mY++;
        helper();
        mY--;

        mCurrIncreasingPathNum--;
        mLastValue = currLastValue;
    }
public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        mMatrix = matrix;
        mMemo = mMatrix;
        for (size_t i = 0; i < mMatrix.size(); ++i)
        {
            for (size_t j = 0; j < mMatrix[0].size(); ++j)
            {
                mMemo[i][j] = 0;
            }
        }
        
        for (size_t i = 0; i < mMatrix.size(); ++i)
        {
            for (size_t j = 0; j < mMatrix[0].size(); ++j)
            {
                mLogestIncreasingPathNum = 0;
                mCurrIncreasingPathNum = 0;
                mX = i;
                mY = j;
                mLastValue = mMatrix[mX][mY]-1;

                helper();

                mMemo[i][j] = mLogestIncreasingPathNum;
            }
        }

        int result = 0;
        for (size_t i = 0; i < mMemo.size(); ++i)
        {
            for (size_t j = 0; j < mMemo[0].size(); ++j)
            {
                if (result < mMemo[i][j])
                {
                    result = mMemo[i][j];
                }
            }
        }
        return result;
    }
};

int main()
{
    std::vector<std::vector<int> > matrix;
    matrix.resize(3);
    matrix[0].push_back(9);
    matrix[0].push_back(9);
    matrix[0].push_back(4);
    matrix[1].push_back(6);
    matrix[1].push_back(6);
    matrix[1].push_back(8);
    matrix[2].push_back(2);
    matrix[2].push_back(1);
    matrix[2].push_back(1);

    Solution s;
    int result = s.longestIncreasingPath(matrix);
    std::cout <<result<< std::endl;
}
