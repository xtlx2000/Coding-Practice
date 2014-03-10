#include <iostream>
using namespace std;

//1 找出状态表达式 s[i][j] = k，从i到j的子串是否为一个回文
//2 根据状态表达式找出各个状态
//  <1> s[i][i] = 1
//  ......自己算
//3 根据各个状态找出大状态依赖小状态的递推关系
//  <1> s[i][i] =1
//  <2> s[i][i+1]根据str[i]==str[i+1]直接判断
//  <3> s[i][j](其中j>i+1)则直接判断str[i] == str[j]如果相同则根据小状态s[i+1][j-1]来判断
//4 conding
//5 check
class Solution{
public:
    bool isPalindromic[100][100];
    bool isValid[100][100];

    int longestPalindromicSubstring(string str)
    {
        //1准备备忘录
        //2初始化备忘录
        for(int i = 0; i < str.size(); i++){
            for(int j = 0; j < str.size(); j++){
                isPalindromic[i][j] = false;
                isValid[i][j] = false;
            }
        }

        //3递归关系式
        //case 1
        for(int i = 0; i < str.size(); i++){
            isPalindromic[i][i] = true;
            isValid[i][i] = true;
        }
        //case 2
        for(int i = 0; i < str.size()-1; i++){
            if(str[i] == str[i+1]){
                isPalindromic[i][i+1] = true;
            }else{
                isPalindromic[i][i+1] = false;
            }
            isValid[i][i+1] = true;

        }
        //case 3
        for(int i = 0; i < str.size(); i++){
            for(int j = 0; j < str.size(); j++){

                if(
                   (i > j)||
                   (i == j)||
                   (j == i+1)
                   ){

                    continue;

                }else if(j > i+1){
                    isPalindromic[i][j] = judge(str, i, j);
                    isValid[i][j] = true;
                }

            }
        }

        int longest = 0;
        for(int i = 0; i < str.size(); i++){
            for(int j = 0; j < str.size(); j++){
                if(isPalindromic[i][j] == true){
                    int longth = j-i+1;
                    if(longth > longest){
                        longest = longth;
                    }
                }
            }
        }

        return longest;

    }

    bool judge(string str, int i, int j){
        if(isValid[i][j] == true){
            return isPalindromic[i][j];
        }
        if(str[i] == str[j]){
            return judge(str, i+1, j-1);
        }else{
            return false;
        }
    }
};

int main()
{
    string str = "aaba";
    Solution s;
    cout <<s.longestPalindromicSubstring(str)<<endl;
}
