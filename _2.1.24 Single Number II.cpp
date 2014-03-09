#include <iostream>
using namespace std;

//1 ���������ҳ���  O(nlogn)  O(1)
//2 λͼ              O(n)      O(x)
//3 ^                 O(n)      O(1)
//  3.1 ��int����ģ��λ��Ȼ��int[i]����3�κ�int[i]��0
//  3.2 �ö�����λ����ģ��������λ����


int function1(int *a, int num);
int function2(int *a, int num);

int main()
{
    int a[10] = {1,2,3,1,2,3,1,2,3,4};
    cout <<function1(a, 10)<<endl;
    cout <<function2(a, 10)<<endl;
}


int function1(int *a, int num)
{
    int BIT = 32;//int
    int bits[BIT];
    for(int i = 0; i < BIT; i++){
        bits[i] = 0;
    }

    for(int i = 0; i < num; i++){
        for(int j = 0; j < BIT; j++){
            bits[j] += (a[i]>>j) & 1;
            bits[j] %= 3;
        }
    }

    int result = 0;
    for(int i = 0; i < BIT; i++){
        result += (bits[i] << i);
    }
    return result;
}


int function2(int *a, int num)
{
    int one = 0, two = 0, three = 0;

    for(int i = 0; i < num; i++){
        int tmp = one & a[i];   //1 one��a[i]��ȡ������
        two |= tmp;             //2 ��one����Щ��two,����ӵ�two
        one ^= a[i];            //3 ��one����ӵ�two��λ��one��ɾ��
        three = ~(one & two);   //4 ��oneλ��twoλ�����ڵ�λ��three����0��three����λ��1

        one &= three;           //5 ��three��0λ(����ոյó�����3�ε�λ)��one�����
        two &= three;           //6 ��three��0λ(����ոյó�����3�ε�λ)��two�����
    }

    return one; //one���յ�λΪ����������3�ε�λ

    return 0;
}
