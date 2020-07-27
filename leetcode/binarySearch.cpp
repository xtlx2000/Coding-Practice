#include <iostream>
#include <vector>

class BinarySearcher
{
    std::vector<int> mVec;
    int mTarget;

public:
    int Solve(const std::vector<int>& vec, int target)
    {
        mVec = vec;
        mTarget = target;

        int size = vec.size();
        int start = 0;
        int end = size - 1;

        while (start + 1 < end)
        {
            int mid = start + (end - start)/2;
            if (vec[mid] == target)
            {
                return mid;
            }
            else if (vec[mid] > target)
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }

        if (vec[start] == target)
        {
            return start;
        }
        if (vec[end] == target)
        {
            return end;
        }

        return -1;
    }
};

int main () 
{
    std::vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    vec.push_back(7);
    
    BinarySearcher b;
    std::cout << b.Solve(vec, 1) << std::endl;
}
