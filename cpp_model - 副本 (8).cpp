#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <fstream>
using namespace std;
#define NODEMAX 20
class Test {
public:
    static std::vector<int>nodeMin;
    static std::vector<int>nodeMax;
    static std::vector<int>leafMin;
    static std::vector<int>leafMax;
    static std::map<std::vector<int>,int> tNum;

    static int treeNum(int n,int m,int level){
        std::vector<int> nml;
        nml.push_back(n);
        nml.push_back(m);
        nml.push_back(level);
        std::map<std::vector<int>,int> ::iterator it=tNum.find(nml);
        if(it!=tNum.end())
            return it->second;
        //
        if(level<=1)return 0;
        //if(level<=1||level>=n)return 0;
        int res=0;
        int sumNode=n-1;//左右子树的结点总数
        int minLevel=level-2;//左右子树的最小深度

        for(int leftLevel=minLevel;leftLevel<level;++leftLevel){
            if(leftLevel<0)continue;
            for(int rightLevel=minLevel;rightLevel<level;++rightLevel){
                if(rightLevel<0)continue;
                if(leftLevel==minLevel&&rightLevel==minLevel)//左右子树深度不能同时为level-2
                    continue;
                 for(int leftNode=nodeMin[leftLevel];leftNode<=sumNode&&leftNode<=nodeMax[leftLevel];++leftNode){
                     int rightNode=sumNode-leftNode;
                     if(rightNode>nodeMax[rightLevel])
                         continue;
                     if(rightNode<nodeMin[rightLevel])
                         break;
                     for(int leftLeaf=leafMin[leftLevel];leftLeaf<=leftNode&&leftLeaf<=m&&leftLeaf<=leafMax[leftLevel];++leftLeaf){
                         int rightLeaf=m-leftLeaf;
                         if(rightLeaf>leafMax[rightLevel]||rightLeaf>rightNode)
                             continue;
                         if(rightLeaf<leafMin[rightLevel])
                             break;
                         int leftTree=treeNum(leftNode,leftLeaf,leftLevel);
                         int rightTree=0;
                         if(leftTree)
                             rightTree=treeNum(rightNode,rightLeaf,rightLevel);
                         res+=leftTree*rightTree;
                     }//for
                }//for
            }//for
        }//for

        tNum.insert(make_pair(nml,res));
        return res;
    }

    static int calculate (int   n,int   m){
        static bool firstTime=true;
        if(firstTime){
            firstTime=false;
            nodeMin.push_back(0);
            nodeMin.push_back(1);
            nodeMax.push_back(0);
            nodeMax.push_back(1);
            leafMin.push_back(0);
            leafMin.push_back(1);
            leafMax.push_back(0);
            leafMax.push_back(1);
            int index=nodeMin.size()-1;
            while(nodeMin[index]<NODEMAX){
                nodeMin.push_back(nodeMin[index]+nodeMin[index-1]+1);
                nodeMax.push_back(nodeMax[index]+nodeMax[index]+1);

                leafMin.push_back(leafMin[index]+leafMin[index-1]);
                leafMax.push_back(leafMax[index]+leafMax[index]);

                index=nodeMin.size()-1;
            }//while
            //for(index=0;index<nodeMin.size();++index)
            //  std::cout<<"level="<<index<<":"<<nodeMin[index]<<" "<<nodeMax[index]<<" "<<leafMin[index]<<" "<<leafMax[index]<<std::endl;
            std::vector<int> nml;//ie： n、m、level
            nml.push_back(0);
            nml.push_back(0);
            nml.push_back(0);
            tNum.insert(make_pair(nml,1));
            nml[0]=1;
            nml[1]=1;
            nml[2]=1;
            tNum.insert(make_pair(nml,1));
            /*将第二层中的能构成平衡二叉树的情况提前计算出来，可以减少一次递归次数
              需要将treeNum中的if(level<=1)修改成if(level<=1||level>=n)return 0;
            nml[0]=2;
            nml[1]=1;
            nml[2]=2;
            tNum.insert(make_pair(nml,2));
            nml[0]=3;
            nml[1]=2;
            nml[2]=2;
            tNum.insert(make_pair(nml,1));
            */
        }//if(firstTime)

        int res=0;
        for(int level=1;level<leafMin.size();++level)
            if(m>=leafMin[level]&&m<=leafMax[level]&&n>=nodeMin[level]&&n<=nodeMax[level])
                res+=treeNum(n,m,level);
        return res;
    }
};
std::vector<int>Test::nodeMin;
std::vector<int>Test::nodeMax;
std::vector<int>Test::leafMin;
std::vector<int>Test::leafMax;
std::map<std::vector<int>,int>Test::tNum;

//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main(){

    //C++提交不成功，生成的结果却能提交C成功，感觉英雄会本道题的C++提交有问题
    std::cout<<Test::calculate(1,1)<<endl;
    std::cout<<Test::calculate(2,1)<<endl;
    std::cout<<Test::calculate(2,2)<<endl;

}
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。
