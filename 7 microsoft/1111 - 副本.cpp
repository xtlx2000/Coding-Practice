#include <iostream>
#include <cstdio>
#include <string.h>
#include <map>
#include <sstream>
using namespace std;


map<string, string> nameDict;
map<string, string> phoneDict;

void do_save(string name, string phone)
{
    if(nameDict.size() >= 200){
        cout <<"error"<<endl;
        return;
    }

    map<string, string>::iterator iter;
    iter = nameDict.find(name);
    if(iter != nameDict.end()){
        cout <<"error"<<endl;
        return;
    }

    nameDict[name] = phone;
    phoneDict[phone] = name;
    cout <<name<< " " <<phone<<endl;
    return;
}

void do_getName(string phone)
{
    map<string, string>::iterator iter;
    iter = phoneDict.find(phone);
    if(iter == phoneDict.end()){
        cout <<"error"<<endl;
        return;
    }

    cout <<(iter)->second<<endl;
}

void do_getPhoneNum(string name)
{
    map<string, string>::iterator iter;
    iter = nameDict.find(name);
    if(iter == nameDict.end()){
        cout <<"error"<<endl;
        return;
    }

    cout <<(iter)->second<<endl;
}

void do_delete(string name)
{
    map<string, string>::iterator iter;
    iter = nameDict.find(name);
    if(iter == nameDict.end()){
        cout <<"error"<<endl;
        return;
    }

    string phone = (iter)->second;

    nameDict.erase(iter);
    phoneDict.erase(phoneDict.find(phone));

    cout <<"ok"<<endl;
}

void do_count()
{
    cout <<nameDict.size()<<endl;
}

void do_clear()
{
    nameDict.clear();
    phoneDict.clear();
}


int main()
{
    char buffer[256];
    memset(buffer, 0, 256);

    char *ptr;
    while(gets(buffer)){
        string tmpStr(buffer);

        istringstream sin(tmpStr);
        string x1;

        while(sin >> x1){
            if(x1 == "save"){
                string name;
                sin >> name;

                string phone;
                sin >> phone;

                do_save(name, phone);

            }else if(x1 == "getName"){
                string phone;
                sin >> phone;

                do_getName(phone);

            }else if(x1 == "getPhoneNum"){
                string name;
                sin >> name;

                do_getPhoneNum(name);

            }else if(x1 == "delete"){
                string name;
                sin >> name;

                do_delete(name);

            }else if(x1 == "count"){

                do_count();

            }else if(x1 == "clear"){

                do_clear();
            }
        }

        memset(buffer, 0, 256);
    }


}


