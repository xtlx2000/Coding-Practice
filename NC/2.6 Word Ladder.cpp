#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//input
string dict[] = {
    "hot",
    "dot",
    "dog",
    "lot",
    "log"
};
int num = 5;
string start = "hit";
string end = "cog";

//output
int currStepNum;
int minStepNum = 65535;
map<string, bool> isUsed;
vector<string> currPath;
vector<string> minPath;

//0 equal
//1
//2
//3
int compare(string str1, string str2)
{
    int notEqualNum = 0;
    for(int i = 0; i < str1.size(); i++){
        if(str1[i] != str2[i]){
            notEqualNum++;
        }
    }
    return notEqualNum;
}

int wordLadder(int level)
{
    if(level >= num){

        if(start == end){

            if(minStepNum > currStepNum){
                minStepNum = currStepNum;
            }
        }

        return minStepNum;
    }

    for(int i = 0; i < num; i++){

        //����2����ʱ�����ǹؼ�������Ⲣ���Ǹ������������п�������;�͸��³ɹ�����˳���
        //       ������������Ҷ�ӽڵ����жϽ��������һ���Ҫ����;ÿ�θ���ǰ�ж��Ƿ�ɹ���
        //judge if only onw char different with end, if so, we find a solution!
        if(compare(start, end) == 1){

            if(minStepNum > currStepNum+1){
                minStepNum = currStepNum+1;
                minPath = currPath;

            }


            return minStepNum;
        }
        //����3�������ж��Ƿ�ǰ���Ѿ��ù����dict�ˣ�
        //judge if dict[i] is also been used!
        if(isUsed[dict[i]]){
            continue;
        }

        //judge if only one char different with dict[i]
        if(compare(start, dict[i]) != 1){
            continue;
        }
        //set
        //����1��set��map���֣�Ӧ����set<string>��map<string, bool>
        //      set�Ĳ�����set.insert(string),map�Ĳ�����map[string] = bool;
        isUsed[dict[i]] = true;
        currStepNum++;
        string oldStart = start;
        start = dict[i];
        currPath.push_back(start);
        //recursion
        wordLadder(level+1);
        //repeal
        isUsed[dict[i]] = false;
        currStepNum--;
        start = oldStart;
        currPath.pop_back();
    }

    return minStepNum;
}

int main()
{
    cout <<wordLadder(0)<<endl;

    //����1��vector��ͷ�����뺯����vector.insert(iter, string)
    minPath.insert(minPath.begin(), start);
    minPath.push_back(end);

    for(vector<string>::iterator iter = minPath.begin();
        iter != minPath.end();
        iter++){

        cout <<*iter<<"-->";
    }
    cout <<"NULL"<<endl;
}





