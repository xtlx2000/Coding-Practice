
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int howmany (int x,int y)
{
    if(x < 1 || x > y)
        return 0;

    bool * bPrime = (bool *)malloc(y * sizeof(bool));
    bPrime[0] = false;
    bPrime[1] = false;
    for(int i = 2; i < y; i++)
    {
        bPrime[i] = true;
    }

    for(int i = 2; i < y; i ++)
    {
        if(bPrime[i])
        {
            if(y/i < i)
            {
                break;
            }

            for(int j = i * i; j < y; j += i)
            {
                bPrime[j] = false;
            }
        }
    }

    int nPrime = 0;
    for(int i = 2; i < y; i++)
    {
        if(bPrime[i])
            nPrime++;
    }


    int * Prime = (int *)malloc(nPrime * sizeof(int));
    for(int i = 2, j = 0; i < y; i++)
    {
        if(bPrime[i])
        {
            Prime[j++] = i;
        }
    }

    int nHalfPrime = 0;
    for(int i = 0; i < nPrime; i++)
    {
        if(y / Prime[i] < Prime[i])
        {
            break;
        }

        for(int j = i; j < nPrime; j++)
        {

            if(j != i && y / Prime[i] < Prime[j])
            {
                break;
            }

            int HalfPrime = Prime[i] * Prime[j];
            if(HalfPrime >= x)
            {
                nHalfPrime++;
            }
        }
    }

    free(Prime);
    free(bPrime);
    return nHalfPrime;
}
//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{
    printf("%d",howmany(2,20000000));
}
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。
