//�����������ֵΪ1Ԫ��3Ԫ��5Ԫ��Ӳ������ö����������ٵ�Ӳ�Ҵչ�11Ԫ��

#include <iostream>
#include <algorithm>
using namespace std;

/* (1) �ҳ���״̬����d(i) = j  �չ�iԪǮ������Ҫj��Ӳ��
 * (2) �ҳ�����״̬�������ҳ���״̬������״̬�Ĺ�ϵ��
   d(0) = 0
 * d(1) = 1 + d(0) = 1+0=1
 * d(2) = 1 + d(1) = 1+1=2
 * d(3) = min{1+d(2), 3+d(0)}
 * d(4) = min{1+d(3), 3+d(1)}
 * d(5) = min{1+d(4), 3+d(2), 5+d(0)}
 * ...
 * (3) �ܽ����״̬������״̬�Ĺ�ϵ���������ƹ�ϵʽ��
 * d(i) = min{1+d(i-x)} ����xΪС�ڵ���i��Ǯ����ֵ
 * (4) code
 * (5) check
 */
#define MAXSIZE 65535
int function(int a[], int n, int num);
int main()
{
    int a[3] = {1,3,5};
    int num = 11;

    cout << function(a, 3, num) <<endl;
}

int function(int a[], int n, int num)
{
    //1 ׼������¼
    int minTable[num+1];
    for(int i = 0; i < num; i++){
        minTable[i] = MAXSIZE;
    }

    //2 ѭ����С�����������¼
    for(int i = 0; i <= num; i++){
        //2.1 �����ʼ״̬
        if(i == 0){
            minTable[i] = 0;
        }
        //2.2 ���ƹ�ϵʽ
        for(int j = 0; j < n; j++){
            if(a[j] <= i){
                minTable[i] = min(
                                (minTable[i]),
                                (1 + minTable[i-a[j]])
                             );
            }
        }
    }
    //3 ����
    return minTable[num];
}
