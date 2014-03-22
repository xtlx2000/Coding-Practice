#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstddef>
using namespace std;

string result;

class HelloWord {
public:
    static string getInfo(string str)
    {
        string left = str;
        while(left.length() != 0){
            left = once(left);
        }

        return "";
    }

    static string once(string str)
    {
        int MAXTIME;
        int MAXMED;
        string str1;
        string str2;
        string str3;
        std::size_t found;

        found = str.find("\n");
        str1 = str.substr(0, found);
        str = str.substr(found+1);

        found = str.find("\n");
        str2 = str.substr(0, found);
        str = str.substr(found+1);

        found = str.find("\n");
        str3 = str.substr(0, found);

        //cout <<str.length()<<endl;
        str = str.substr(found+1);
        //cout <<str.length()<<endl;

        //cout <<"str1 length="<<str1.length()<<"  "<<str1;
        //cout <<"str2 length="<<str2.length()<<"  "<<str2;
        //cout <<"str3 length="<<str3.length()<<"  "<<str3<<endl;
        //cout <<"str length="<<str.length()<<"  "<<str<<endl;

        if(str1.length() + str2.length() != str3.length()){
            //result +="NO\n";
            cout <<"NO"<<endl;
            return str;
        }

        int i = 0;
        int j = 0;
        int k;

        for(k = 0; k < str3.length(); k++){
            if(str3[k]== str1[i]){
                i++;
            }else if(str3[k] == str2[j]){
                j++;
            }else{
                //result += "NO\n";
                cout <<"NO"<<endl;
                return str;
            }
        }

        //cout <<i<<endl;
        //cout <<j<<endl;
        //cout <<k<<endl;

        if( (i == str1.length())
            && (j == str2.length())
            && (k == (str3.length()))
           ){
            //result += "YES\n";
            cout <<"YES"<<endl;
        }else{
            //result += "NO\n";
            cout <<"NO"<<endl;
        }

        return str;
    }
};
int main()
{
    string c=HelloWord::getInfo("a\nb\nab\na\nb\nca\n");
    //string c = HelloWord::once("a\nb\nab\na\nb\nca\n");
    //c = HelloWord::once(c);
    cout<<c<<endl;

}
