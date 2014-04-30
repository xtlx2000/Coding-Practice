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

        //卡壳2：何时结束是关键！这个题并非是个满二叉树！有可能在中途就更新成功！因此除了
        //       在满二叉树的叶子节点上判断结束，而且还需要在中途每次更新前判断是否成功。
        //judge if only onw char different with end, if so, we find a solution!
        if(compare(start, end) == 1){

            if(minStepNum > currStepNum+1){
                minStepNum = currStepNum+1;
                minPath = currPath;

            }


            return minStepNum;
        }
        //卡壳3：忘了判断是否前面已经用过这个dict了！
        //judge if dict[i] is also been used!
        if(isUsed[dict[i]]){
            continue;
        }

        //judge if only one char different with dict[i]
        if(compare(start, dict[i]) != 1){
            continue;
        }
        //set
        //卡壳1：set和map不分！应该是set<string>或map<string, bool>
        //      set的插入是set.insert(string),map的插入是map[string] = bool;
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

    //卡壳1：vector的头部插入函数是vector.insert(iter, string)
    minPath.insert(minPath.begin(), start);
    minPath.push_back(end);

    for(vector<string>::iterator iter = minPath.begin();
        iter != minPath.end();
        iter++){

        cout <<*iter<<"-->";
    }
    cout <<"NULL"<<endl;
}





