#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Test {
public:
    static int position (int   x,int   y)
    {
        if(
           (x != y)
            &&((x - y) != 2)
           ){

            return -1;
        }

        //1 even
        if(x % 2 == 0){
            //1,1 ==
            if(x == y){
                return 2*x;
            }else{
            //1.2 x-y==2
                return x+y;
            }
        }else{
        //2 odd
            //2.1 ==
            if(x == y){
                return 2*x-1;
            }else{
            //2.2 x-y==2
                return x+y-1;
            }
        }
    }
};

//start ��ʾ���Զ��ľ���ʼΨһ��ʶ������ɾ�������ӡ�
int main()
{
    cout<<Test::position(0,0)<<endl;
    cout<<Test::position(1,1)<<endl;
    cout<<Test::position(2,0)<<endl;
    cout<<Test::position(3,1)<<endl;
}
//end //��ʾ���Զ��ľ����Ψһ��ʶ������ɾ�������ӡ�
