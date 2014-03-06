#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstddef>
using namespace std;

#define MAXVALUE 10000

string result;

class HelloWord {
public:
    static string getInfo(string str)
    {
        if(str.size() < 5){
            return result;
        }
        int MAXTIME;
        int MAXMED;
        string tmpStr;
        std::size_t found;

        found = str.find(" ");
        tmpStr = str.substr(0, found);//"70"
        MAXTIME = atoi(tmpStr.c_str());//70
        str = str.substr(found+1);

        found = str.find("\n");
        tmpStr = str.substr(0, found);//"3"
        MAXMED = atoi(tmpStr.c_str());//3
        str = str.substr(found+1);

        int *time = (int *)malloc(MAXMED*sizeof(int));
        int *value = (int *)malloc(MAXMED*sizeof(int));

	//int *tmp = (int *)malloc(MAXMED*(MAXTIME+1)*sizeof(int));
        //int **maxTable = tmp;
	int maxTable[100][1000];

        for(int i = 0; i < MAXMED; i++){
            found = str.find(" ");
            tmpStr = str.substr(0, found);//"71"
            time[i] = atoi(tmpStr.c_str());//71
            str = str.substr(found+1);

            found = str.find("\n");
            tmpStr = str.substr(0, found);//"100"
            value[i] = atoi(tmpStr.c_str());//100
            str = str.substr(found+1);
        }

        for(int i = 0; i < MAXMED; i++){
            maxTable[i][0] = 0;
        }

        for(int j = 0; j < MAXTIME+1; j++){
            if(j >= time[0]){
                maxTable[0][j] = value[0];
            }else{
                maxTable[0][j] = 0;
            }
        }

        for(int i = 1; i < MAXMED; i++){
            for(int j = 1; j < MAXTIME+1; j++){

                int maybeMax = 0;
                if(j > time[i]){
                    maybeMax = value[i] + maxTable[i-1][j-time[i]+1];
                }

                maxTable[i][j] = max(
                                     (maxTable[i-1][j]),
                                     (maybeMax)
                                     );
            }
        }

        char buffer[64];
        memset(buffer, 0, 64);
        sprintf(buffer, "%d\n", maxTable[MAXMED-1][MAXTIME]);
        result += buffer;

        //cout <<"tmpStr='"<<tmpStr<<"'"<<endl;
        //cout <<"str='"<<str<<"'"<<endl;

        return getInfo(str);
    }

};
int main()
{
    string c=HelloWord::getInfo("70 3\n71 100\n69 1\n1 2\n215 98\n42 1\n182 22\n61 44");
    cout<<c<<endl;
}
