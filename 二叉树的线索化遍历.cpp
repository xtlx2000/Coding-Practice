#include <iostream>
using namespace std;

struct TreeNode
{
    int value;
    struct TreeNode *left, *right;

    void set(int value_, struct TreeNode *left_, struct TreeNode *right_)
    {
        this->value = value_;
        this->left = left_;
        this->right = right_;
    }
};

//thread traverse inorder
void thread_inorder(struct TreeNode *tree)
{
    struct TreeNode *cur = tree;
    struct TreeNode *prev;

    while(cur){
        //1 找cur的前驱
        prev = cur->left;
        //  1.1 cur没前驱，说明它是最小元素
        if(!prev){
            cout <<cur->value<<" ";
            cur = cur->right;
        //  1.2 cur有前驱
        }else{
            //1.2.1 如果cur有前驱且前驱没有被线索化(前驱的右孩子不是cur)，则线索话这个前驱
            while(prev->right && prev->right != cur){
                prev = prev->right;
            }

            //1.2.1 设置线索指针
            if(prev->right == NULL){
                //将cur的前驱prev的右孩子设置为cur
                prev->right = cur;
                //cur更新为cur->left
                cur = cur->left;

            //1.2.2 撤销线索指针
            }else{
                prev->right = NULL;
                cout <<cur->value<<"->";
                cur = cur->right;
            }
        }
    }
}

int main()
{
    struct TreeNode *tree = new (struct TreeNode);
    struct TreeNode *tmp1 = new (struct TreeNode);
    struct TreeNode *tmp2 = new (struct TreeNode);
    struct TreeNode *tmp3 = new (struct TreeNode);
    struct TreeNode *tmp4 = new (struct TreeNode);
    struct TreeNode *tmp5 = new (struct TreeNode);
    struct TreeNode *tmp6 = new (struct TreeNode);

    tree->set(10, tmp1, tmp2);
    tmp1->set(5, tmp3, tmp4);
    tmp2->set(15, NULL, NULL);
    tmp3->set(1, NULL, NULL);
    tmp4->set(8, tmp5, tmp6);
    tmp5->set(6, NULL, NULL);
    tmp6->set(9, NULL, NULL);

    thread_inorder(tree);
}
