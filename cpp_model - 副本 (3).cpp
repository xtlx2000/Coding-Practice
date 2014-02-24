#include <iostream>
using namespace std;

long reverse(long num)
{
    int result = 0;
    int reminder;
    int negative = 0;

    if(num < 0){
        num = -num;
        negative = 1;
    }

    while(num % 10 >= 0 && num > 0){
        reminder = num %10;
        result = result *10 + reminder;
        num = int(num / 10);
    }

    if(negative == 1){
        result = -result;
    }

    return result;
}

int main()
{
}
