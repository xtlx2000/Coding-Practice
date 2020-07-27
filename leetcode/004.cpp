#include <iostream>
#include <vector>

class MiddleFinder
{
    std::vector<std::vector<int> > mVecs;
    int mStart1;
    int mStart2;

    int findKth(int k)
    {
        // end condition
        if (k == 1)
        {
            if (mStart1 >= mVecs[0].size())
            {
                return mVecs[1][mStart2];
            }
            if (mStart2 >= mVecs[1].size())
            {
                return mVecs[0][mStart1];
            }
            if (mVecs[0][mStart1] <= mVecs[1][mStart2])
            {
                return mVecs[0][mStart1];
            }
            else
            {
                return mVecs[1][mStart2];
            }
        }

        int halfK = k/2;
        int idx1 = mStart1 + halfK - 1 > mVecs[0].size()-1 ? mVecs[0].size()-1 : mStart1 + halfK - 1;
        int idx2 = mStart2 + halfK - 1 > mVecs[1].size()-1 ? mVecs[1].size()-1 : mStart2 + halfK - 1;

        int diff = 0;
        if (mVecs[0][idx1] >= mVecs[1][idx2])
        {
            diff = idx2 - mStart2 + 1;
            mStart2 = idx2 + 1;
        }
        else
        {
            diff = idx1 - mStart1 + 1;
            mStart1 = idx1 + 1;
        }

        return findKth(k - diff);
    }

public:
    float Solve(const std::vector<std::vector<int> >& vecs)
    {
        if (vecs.size() != 2)
        {
            return 0;
        }

        mVecs = vecs;
        mStart1 = 0;
        mStart2 = 0;
        size_t size1 = vecs[0].size();
        size_t size2 = vecs[1].size();

        if ((size1 + size2) % 2 == 0)
        {
            return (findKth((size1+size2)/2) + findKth((size1+size2)/2+1))/2;
        }
        else
        {
            return findKth((size1+size2)/2);
        }
    }
};


int main()
{
    std::vector<std::vector<int> > vecs;
    vecs.resize(2);
    vecs[0].push_back(1);
    vecs[0].push_back(3);
    vecs[0].push_back(5);
    vecs[0].push_back(7);
    vecs[0].push_back(9);
    vecs[1].push_back(2);
    vecs[1].push_back(4);
    vecs[1].push_back(6);
    vecs[1].push_back(8);
    vecs[1].push_back(10);

    MiddleFinder m;
    std::cout << m.Solve(vecs) << std::endl;
}
