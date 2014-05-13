#include <iostream>
using namespace std;


int n;
int main()
{
    cin >> n;
    int num = 0;
    bool a[n+1];
    for(int i = 1; i <= n; i++){
        a[i] = false;
    }

    for(int i = 1; i <= n; i++){//sutdent

        for(int j = 1; j <= n; j++){//light
            if(j % i == 0){
                a[j] = !a[j];
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(a[i] == true){
            num++;
        }
    }

    cout <<num<<endl;
    return 0;
}


