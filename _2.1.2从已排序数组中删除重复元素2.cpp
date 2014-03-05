#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 2) return n;

        int prevNum = A[0]; //��¼��ǰ�ظ�������
        int prevCnt = 1;    //��¼��ǰ���ֳ��ֵĴ���
        int curIdx = 1;     /*
                             * ��¼�´�Ҫ������λ���±꣬
                             * ��A[0]��A[curIdx-1]�Ǵ�����ϵģ�
                             * ������curIdx�Ǵ�����Ϻ�����鳤��
                             */
        for(int i = 1; i < n; ++i)
        {
            //A[i]�Ǹ��ظ���
            if(A[i] == prevNum)
            {
                //A[i]�ظ���2������
                if(prevCnt == 2){
                    continue;//���ֳ���2�����ϣ�û����Ҫ�޸ĵı���

                //A[i]�ظ���1��
                }else{
                    A[curIdx] = A[i];//��Ϊֻ�ظ���1�Σ����������һ��ҪҪ
                    curIdx++;//�����´�д��index
                    prevCnt++;//�����ֳ��ֵĴ�����1
                }
            //A[i]��һ�γ���
            }else{
                A[curIdx] = A[i];//��һ�γ��ֵ�����һ��ҪҪ��
                curIdx++;//�����´�д��index
                prevNum = A[i];//���µ�ǰ�ظ�������
                prevCnt = 1;//���µ�ǰ���ֳ��ֵĴ���
            }
        }
        return curIdx;
    }
};

int main()
{
    int a[10] = {1,1,1,1,2,2,3,3,3,3};
    Solution s;
    cout <<s.removeDuplicates(a, 10)<<endl;

    return 0;
}
