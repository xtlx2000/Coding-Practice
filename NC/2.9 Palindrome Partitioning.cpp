#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

//����1�������ͬ�����Ӽ���������0��1�ֱ����ʲô�أ�����str="abcba"����5��Ԫ�أ�
//�Ӽ�����0��1�뵱Ȼ�Ĵ���ÿ������ȡ�������𣿸������ⲻ��Ԫ�ص�ȡ�ᣬ����ȫ����Ҫȡ����
//�ص��ǻ��֣����Ҫ��ÿ2��Ԫ��֮��ļ������Ԫ�أ�1����ָ��0�����ָ����5��Ԫ��
//��4����������num��ȡֵӦ����4��Ҫ�������⣬��ѵ��


//intput
string str = "abcba";


//output
int num = str.size()-1;
int lastPos;
vector<string> currPartition;
bool isPalindrome(string str)
{
    int mid;
    if(str.size() % 2 == 0){
        mid = str.size()/2;
    }else{
        mid = str.size()/2+1;
    }

    for(int i = 0; i < mid; i++){

        if(str[i] == str[str.size()-i-1]){
        }else{
            return false;
        }
    }

    return true;
}

void palindromePartition(int level)
{
    //����2��һ��Ҫ����ÿ�εݹ�level��ֵ��������һ�㣬������������ע��level����
    if(level >= num){

        if(lastPos >= num){
            for(vector<string>::iterator iter = currPartition.begin();
                iter != currPartition.end();
                iter++){

                cout <<*iter<<",";
            }
            cout <<endl;
        }
        return;
    }

    //case 0
    //set
    //recursion
    palindromePartition(level+1);
    //repeal


    //case 1
    //����3��û��str.substr()���÷�
    string substr = str.substr(lastPos, level+1-lastPos);
    //cout <<lastPos<<"-"<<level+1<<"="<<substr<<endl;

    if(isPalindrome(substr) == true){
        //set
        int oldLastPos = lastPos;
        lastPos = level + 1;
        currPartition.push_back(substr);
        if(level == num - 1){
            substr = str[lastPos];
            currPartition.push_back(substr);
            lastPos += 1;
        }

        //recursion
        palindromePartition(level+1);

        //repeal
        if(level == num-1){
            currPartition.pop_back();
            lastPos -= 1;
        }
        currPartition.pop_back();
        lastPos = oldLastPos;


        return;

    }

}


int main()
{
    palindromePartition(0);
}
