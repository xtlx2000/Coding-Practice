#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;


string start = "hit";
string end = "cog";
string dict[5] = {
    "hot",
    "dot",
    "dog",
    "lot",
    "log"
};
int dictNum = 5;

vector<int> compare(string a, string b)
{
    vector<int> result;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[i]){
            //nothing
        }else{
            result.push_back(i);
        }
    }
    return result;
}

int wordLadder(string start, string end)
{
    queue<string> queue1, queue2;
    queue<> *conrrent= &queue1, *sons = &queue2;
    set<> visited;
    map<string> father;

    set<string> dicts;
    for(int i = 0; i < dictNum; i++){
        dicts.insert(dict[i]);
    }

    if(start == end){
        return 0;
    }

    conrrent.push(start);

    while(!conrrent.empty()){//among layer traverse

        while(!conrrent.empty()){//inter layer traverse

            string tmpString = conrrent.front();
            conrrent.pop();

            vector<string> sonNodes = get_sons(tmpString);
            for(int i = 0; i < dicts.size(); i++){//sons traverse

                if(tmp)
            }


        }
    }
}

vector<string> get_sons(string tmpString)
{

}

int main()
{
    cout <<wordLadder(start, end)<<endl;
}
