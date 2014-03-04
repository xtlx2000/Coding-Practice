#include <iostream>
using namespace std;

void function(int *a, int num)
{
    int index = 0;
    for(int i = 1; i < num; i++){
        if(a[index] == a[i]){
            //++i; skip
        }else{
            a[++index] = a[i];
        }
    }
    cout <<"num="<<index+1<<endl;

    cout <<"list: ";
    for(int i = 0; i < index; i++){
        cout <<a[i]<< " ";
    }
    cout <<endl;
}

int main()
{
    int a[10] = {1,1,2,2,2,3,4,5,6,7};
    function(a, 10);
}
