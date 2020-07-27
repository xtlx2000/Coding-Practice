#include <iostream>
#include <vector>

class MiddleFinder
{
    std::vector<std::vector<int> > mVecs;

    int findKth(int k, int start1, int start2)
    {
        // end condition
        if (k == 1)
        {
            if (start1 >= mVecs[0].size())
            {
                return mVecs[1][start2];
            }
            if (start2 >= mVecs[1].size())
            {
                return mVecs[0][start1];
            }
            if (mVecs[0][start1] <= mVecs[1][start2])
            {
                return mVecs[0][start1];
            }
            else
            {
                return mVecs[1][start2];
            }
        }

        int halfK = k/2;
        int idx1 = start1 + halfK - 1 > mVecs[0].size()-1 ? mVecs[0].size()-1 : start1 + halfK - 1;
        int idx2 = start2 + halfK - 1 > mVecs[1].size()-1 ? mVecs[1].size()-1 : start2 + halfK - 1;

        int diff = 0;
        if (mVecs[0][idx1] >= mVecs[1][idx2])
        {
            diff = idx2 - start2 + 1;
            start2 = idx2 + 1;
            std::cout <<"delete before "<< mVecs[1][idx2] << std::endl;
        }
        else
        {
            diff = idx1 - start1 + 1;
            start1 = idx1 + 1;
            std::cout <<"delete before "<< mVecs[0][idx1] << std::endl;
        }

        return findKth(k - diff, start1, start2);
    }

public:
    float Solve(const std::vector<std::vector<int> >& vecs)
    {
        if (vecs.size() != 2)
        {
            return 0;
        }

        mVecs = vecs;
        size_t size1 = vecs[0].size();
        size_t size2 = vecs[1].size();

        if ((size1 + size2) % 2 == 0)
        {
            return float(findKth((size1+size2)/2, 0, 0) + findKth((size1+size2)/2+1, 0, 0))/2;
        }
        else
        {
            return findKth((size1+size2)/2+1, 0, 0);
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
