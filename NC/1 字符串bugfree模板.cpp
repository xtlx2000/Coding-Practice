#include <iostream>
using namespace std;

/* 注意点：
 * 1 良好的编码风格
 * 2 健康检查
 * 3 想算法，与面试官清晰沟通，时刻明白你的意图，得到他的确认后才开始写代码
 * 4 写完代码后自觉写出testcase并验证
 */

/* 常见错误:
 *  1 KMP你写不出来
 *  2 没空格，编码风格不好
 *  3 i循环次数的计算错误: i < source.size();
 *  4 i循环次数的计算错误：i < source.size()-target.size();
 */

//良好的编码风格
string strstr(string source, string target)
{
    //1 健康检查1：检查是否独自参数是否合法
    if(source.size() == 0 || target.size() == 0){
        return -1;
    }

    //2 健康检查2：检查参数之间是否合法
    if(source.size() < target.size()){
        return -1;
    }

    //注意边界处理，做到bugfree
    for(int i = 0; i < source.size()-target.size()+1; i++){

        for(int j = 0; j < target.size(); j++){
            if(source[i+j] != target[j]){
                break;
            }
        }

        if(j == target.size()){
            return source.substr(i);
        }
    }

    return "";
}




int main()
{
}




