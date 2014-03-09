#include <iostream>
using namespace std;

//1 先排序，在找出来  O(nlogn)  O(1)
//2 位图              O(n)      O(x)
//3 ^                 O(n)      O(1)
//  3.1 用int数组模拟位，然后当int[i]出现3次后将int[i]清0
//  3.2 用二进制位运算模拟三进制位运算


int function1(int *a, int num);
int function2(int *a, int num);

int main()
{
    int a[10] = {1,2,3,1,2,3,1,2,3,4};
    cout <<function1(a, 10)<<endl;
    cout <<function2(a, 10)<<endl;
}


int function1(int *a, int num)
{
    int BIT = 32;//int
    int bits[BIT];
    for(int i = 0; i < BIT; i++){
        bits[i] = 0;
    }

    for(int i = 0; i < num; i++){
        for(int j = 0; j < BIT; j++){
            bits[j] += (a[i]>>j) & 1;
            bits[j] %= 3;
        }
    }

    int result = 0;
    for(int i = 0; i < BIT; i++){
        result += (bits[i] << i);
    }
    return result;
}


int function2(int *a, int num)
{
    int one = 0, two = 0, three = 0;

    for(int i = 0; i < num; i++){
        int tmp = one & a[i];   //1 one从a[i]获取新数据
        two |= tmp;             //2 看one中那些到two,则添加到two
        one ^= a[i];            //3 将one中添加到two的位从one中删除
        three = ~(one & two);   //4 将one位和two位都存在的位在three中置0，three其他位置1

        one &= three;           //5 将three中0位(上面刚刚得出出现3次的位)从one中清空
        two &= three;           //6 将three中0位(上面刚刚得出出现3次的位)从two中清空
    }

    return one; //one最终的位为出现了少于3次的位

    return 0;
}
