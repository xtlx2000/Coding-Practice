#include <iostream>
#include <sstream>
using namespace std;

int conv(const string &s)
{
    string str = s;
    int sign = 0;

    while(str[0] == ' '){
        str = str.substr(1);
        //cout <<"'"<<str<<"'"<<endl;
    }

    if(
       (str[0] < '0' && str[0] >'9')
       &&(str[0] != '+')
       &&(str[0] != '-')
       ){
        return 0;
    }
    if(
       (str[0] == '+')
       ||(str[0] == '-')
       ){
        sign = 1;
    }

    if(sign == 1 &&
       ((str[1] == '+')||(str[1] == '-'))
       ){
        return 0;
    }


    stringstream ss;
    ss << str;
    int num;
    ss >> num;

    return num;
}

int main()
{
    int num = conv("+ -2");
    cout <<num<<endl;
}
