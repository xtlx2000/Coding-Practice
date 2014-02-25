#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class Test {
public:
    static void spreadFromMiddle(int &num, int *buf, int &begin, int &end)
    {
        while (num)
        {
            int value = min(9-buf[begin], num/2);
            buf[begin] += value;
            buf[end] += value;
            num -= 2*value;
            begin--;
            end++;
        }
    }

    static void outputString(int *buf, char *output, int len)
    {
        int result = 0;
        for (int i = 0; i < len; i++)
        {
            result += buf[i];
            output[i] = buf[i] + '0';
        }
    }

    static void arrangeMidOfOddArray(int *buf, int &begin, int &end, int mid, int &num)
    {
        if (buf[mid] > 9)
        {
            if (buf[mid] & 1)
            {
                num += buf[mid] - 9;
                buf[mid] = 9;
            }
            else
            {
                num += buf[mid] - 8;
                buf[mid] = 8;
            }
        }

        begin--;
        end++;
    }

    static string palindrom(string a)
    {
        int totalNum = 0;
        int numOfChar = a.length();

        for (int i = 0; i < numOfChar; i++)
        {
            totalNum += a[i]-'0';
        }

        if (totalNum < 2 || numOfChar < 2)
        {
            return "Impossible";
        }

        int *buf = new int[numOfChar+3];
        char *output = new char[numOfChar+3];
        memset(buf, 0, (numOfChar+3)*sizeof(int));
        memset(output, 0, (numOfChar+3)*sizeof(char));

        int begin = 0;
        int end = numOfChar-1;
        int num = totalNum;
        bool success = false;
        int len = numOfChar;

        bool needExpand = false;
        int mid = len/2;

        if (!(numOfChar & 1) && (totalNum & 1))
        {
            needExpand = true;
        }

        if (!needExpand)
        {
            while ((begin < end) && (num >= 2*(a[begin]-'0')))
            {
                buf[begin] = a[begin]-'0';
                buf[end] = a[begin] - '0';
                num -= 2*(a[begin]-'0');
                begin++;
                end--;
            }
            if (begin != end)
            {
                begin--;
                end++;
            }

            if (begin == end)
            {
                buf[begin] = num;
                num = 0;

                for (int i = begin; i < len; i++)
                {
                    if (buf[i] > a[i]-'0')
                    {
                        success = true;
                        break;
                    }
                    if (buf[i] < a[i]-'0')
                    {
                        break;
                    }
                }

                if (success)
                {
                    arrangeMidOfOddArray(buf, begin, end, mid, num);
                    spreadFromMiddle(num, buf, begin, end);
                }
            }
        }

        int newEnd;
        if (!success && !needExpand)
        {
            if (num < 2)
            {
                int newBegin = begin;

                while (newBegin >= 0 && buf[newBegin] == 0)
                {
                    newBegin--;
                }
                if (newBegin > 0)
                {
                    if (mid == newBegin)
                    {
                        num += buf[newBegin];
                    }
                    else
                    {
                        num += 2*buf[newBegin];
                     }
                     buf[newBegin] = 0;
                     buf[len-1-newBegin] = 0;
                }

                newEnd = newBegin - 1;
            }
            else
            {
                newEnd = begin;

                if (begin == end)
                {
                    newEnd = begin-1;
                    num += buf[mid];
                    buf[mid] = 0;
                }
            }

            while (newEnd >= 0 && buf[newEnd] == 9)
            {
                num += 2*buf[newEnd];
                buf[newEnd] = 0;
                buf[len-1-newEnd] = 0;
                newEnd--;
            }

            if (newEnd >= 0 && num >= 2)
            {
                buf[newEnd]++;
                buf[len-1-newEnd]++;
                num -= 2;

                if (len & 1)
                {
                    begin = end = mid;
                    buf[mid] = num;
                    num = 0;

                    arrangeMidOfOddArray(buf, begin, end, mid, num);
                }
                else
                {
                    begin = mid - 1;
                    end = begin + 1;
                }

                spreadFromMiddle(num, buf, begin, end);
                success = true;
            }
        }

        if (!success)
        {
            if (totalNum & 1)
            {
                if (!(numOfChar & 1))
                {
                    len++;
                }
                else
                {
                    len += 2;
                }
            }
            else
            {
                len += 1;
            }

            memset(buf, 0, len*sizeof(int));
            buf[0] = buf[len-1] = 1;
            num = totalNum - 2;
            mid = len/2;

            if (len & 1)
            {
                begin = end = mid;
                buf[mid] = num;
                num = 0;

                arrangeMidOfOddArray(buf, begin, end, mid, num);
            }
            else
            {
                begin = mid - 1;
                end = begin + 1;
            }

            spreadFromMiddle(num, buf, begin, end);
            success = true;
        }

        if (success)
        {
            outputString(buf, output, len);
            string result(output);

            delete []buf;
            delete []output;
            return result;
        }
        else
        {
            return "Impossible";
        }
    }
};

//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{
    cout<<Test::palindrom("1")<<endl;
}
//end //提示：自动阅卷结束唯一标识，请勿删除或增加
