#include <iostream>
using namespace std;

string intToRoman(int num)
{
    const string symbol[] = {
                                "M",
                                "CM",
                                "D",
                                "CD",
                                "C",
                                "XC",
                                "L",
                                "XL",
                                "X",
                                "IX",
                                "V",
                                "IV",
                                "I"
                            };
    const int radix[] = {
                                1000,
                                900,
                                500,
                                400,
                                100,
                                90,
                                50,
                                40,
                                10,
                                9,
                                5,
                                4,
                                1
                        };

    string roman;
    for(int i = 0; num > 0; ++i){
        int count = num / radix[i];
        num %= radix[i];

        while(count--){
            roman += symbol[i];
        }
    }

    return roman;
}

int main()
{
    cout <<intToRoman(99) <<endl;
}
