#include <iostream>
using namespace std;

//eg: 5,3,4,8,6,7
/* (1)�ҳ�״̬���ʽ��d(i) = j,ǰi��������ǽ������г���Ϊj
 * (2)����״̬���ʽ�ҳ�����״̬
 * d(0) = 0
 * d(1) = 1
 * d(2) = 3>=5 ? d(1)+1 : max{d(1), 1} = 1
 * d(3) = 4>=3 ? d(2)+1 : max{d(2), 1} = 2
 * d(4) = 8>=4 ? d(3)+1 : max{d(3), 1} = 3
 * ...
 * (3)���ݸ���״̬�ҳ���״̬����С״̬�ĵ��ƹ�ϵ
 *  d(i) = (A[i-1] >= A[i-2])? d(i-1)+1 : max{d(i-1), 1}
 * (4)coding
 * (5)check
 */

int function(int *a, int num);

int main()
{
    int a[6] = {5,3,4,8,6,7};
    cout <<function(a, 6)<<endl;
}

int function(int *a, int num)
{
    //1 ׼������¼
    int LongestTable[num+1];
    for(int i = 0; i < num+1; i++){
        LongestTable[i] = 0;
    }

    //2 ��ʼ����ʼ״̬
    LongestTable[0] = 0;

    //3 ���ʽ���ƹ�ϵ
    for(int i = 1; i < num+1; i++){
        LongestTable[i] = a[i-1] >= a[i-2] ?
                            (LongestTable[i-1] + 1) :
                            ( max(
                                  LongestTable[i-1],
                                  1
                                  )
                             );
    }
    //4 ����
    return LongestTable[num];
}
