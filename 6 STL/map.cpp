#include <iostream>
#include <map>
#include <string>
using namespace std;
int main ()
{
  std::map<char,std::string> mymap;

  mymap['a']="an element";
  mymap['b']="another element";
  mymap['c']=mymap['b'];

  std::cout << "mymap['a'] is " << mymap['a'] << '\n';
  std::cout << "mymap['b'] is " << mymap['b'] << '\n';
  std::cout << "mymap['c'] is " << mymap['c'] << '\n';
  //Notice how the last access (to element 'd') inserts a new element in the map with that key and initialized to its default value (an empty string) even though it is accessed only to retrieve its value.
  std::cout << "mymap['d'] is " << mymap['d'] << '\n';

  std::cout << "mymap now contains " << mymap.size() << " elements.\n";

  if(mymap.find('e') == mymap.end()){
      cout <<"not found"<<endl;
  }

  return 0;
}
