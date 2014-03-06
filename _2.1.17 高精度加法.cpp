#include <iostream>
using namespace std;

class Solution{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        add(digits, 1);
        return digits;
    }
private:
    //0 <= digit <= 9
    void add(vector<int> &digits, int digit)
    {
        int c = digit;//carry bit

        for(vector<int>::iterator iter = digits.begin();
            iter != dights.end();
            iter++){

            *it += c;
            c = *it / 10;
            *it %= 10;
        }

        if(c > 0){
            digits.insert(digits.begin(), 1);
        }
    }
};


int main()
{
}
