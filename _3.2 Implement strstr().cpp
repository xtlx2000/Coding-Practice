#include <iostream>
using namespace std;

//1 ����ƥ��
class Solution{
public:
    char *strstr(const char *haystack, const char *needle)
    {
        if(!*needle){
            return (char*)haystack;
        }

        const char *p1;
        const char *p2;
        const char *p1_advance = haystack;
        for(p2 = &needle[1]; *p2; ++p2){
            p1_advance++;
        }

        for(p1 = haystack; *p1_advance; p1_advance++){
            char *p1_old = (char *)p1;
            p2 = needle;
            while(*p1 && *p2 && *p1 == *p2){
                p1++;
                p2++;
            }
            if(!*p2){
                return p1_old;
            }
            p1 = p1_old + 1;
        }
        return p1_old + 1;
    }
};

//2 KMP

int main()
{
}
