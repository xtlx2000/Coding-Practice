#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;



int main()
{
    unordered_map<string, int> hashTable;

    hashTable["hello"] = "1";
    hashTable["world"] = "2";

    cout <<hashTable["world"]<<endl;
    cout <<hashTable["hello"]<<endl;
}
