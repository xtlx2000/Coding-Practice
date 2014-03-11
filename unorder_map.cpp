#include <iostream>
#include <map>
using namespace std;


int main()
{
    map<string, bool> stringmap;

    cout <<stringmap["lpc"]<<endl;
    stringmap["lpc"] = true;
    cout <<stringmap["lpc"]<<endl;
}
