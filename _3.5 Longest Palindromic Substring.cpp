#include <iostream>
using namespace std;

//1 �ҳ�״̬���ʽ s[i][j] = k����i��j���Ӵ��Ƿ�Ϊһ������
//2 ����״̬���ʽ�ҳ�����״̬
//  <1> s[i][i] = 1
//  ......�Լ���
//3 ���ݸ���״̬�ҳ���״̬����С״̬�ĵ��ƹ�ϵ
//  <1> s[i][i] =1
//  <2> s[i][i+1]����str[i]==str[i+1]ֱ���ж�
//  <3> s[i][j](����j>i+1)��ֱ���ж�str[i] == str[j]�����ͬ�����С״̬s[i+1][j-1]���ж�
//4 conding
//5 check
class Solution{
public:
    bool isPalindromic[100][100];
    bool isValid[100][100];

    int longestPalindromicSubstring(string str)
    {
        //1׼������¼
        //2��ʼ������¼
        for(int i = 0; i < str.size(); i++){
            for(int j = 0; j < str.size(); j++){
                isPalindromic[i][j] = false;
                isValid[i][j] = false;
            }
        }

        //3�ݹ��ϵʽ
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
