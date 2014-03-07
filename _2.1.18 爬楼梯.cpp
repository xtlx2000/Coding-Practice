#include <iostream>
using namespace std;

/*
 * ��f(i)Ϊ��0��i�׵���·��������
 * ÿ�ζ���2��ѡ�񣺴ӵ�i���ߣ�Ҫô��1�׵���(i+1)��Ҫô��2�׵���(i+2)��
 * ������nʱ���п����Ǵ�n-1��������Ǵ�n-2����ݹ�֮���ã�
 *          f(n) = f(n-1) + f(n-2)���ó����Ǹ�fanbonichi����
 */

//�ݹ�,ʱ�临�Ӷ�O(2^n)
int walk1(int n)
{
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    return walk1(n-1) + walk1(n-2);
}

//���������õ�����fanbonachi����
//f(n) = f(n-1) + f(n-2)
//ʱ�临�Ӷ�O(n)
int walk2(int n)
{
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }

    int first = 1;
    int second = 2;
    int result = 0;
    for(int i = 3; i <= n; i++){
         result = first + second;
         first = second;
         second = result;
    }
    return result;
}


int main()
{
    cout <<walk1(40)<<endl;
    cout <<walk2(40)<<endl;
}
