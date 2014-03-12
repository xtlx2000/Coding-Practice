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

bool PathSum(struct TreeNode *root, int prevSum, int target)
{
    bool ret_left = false;
    bool ret_right = false;
    int tmpSum = prevSum + root->value;

    if(root->left){
        ret_left = PathSum(root->left, tmpSum, target);
    }
    if(root->right){
        ret_right = PathSum(root->right, tmpSum, target);
    }

    if(!root->left && !root->right){
        if(tmpSum == target){
            return true;
        }else{
            return false;
        }
    }

    return (ret_left || ret_right);

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

    cout <<PathSum(tree, 0, 32)<<endl;
    cout <<PathSum(tree, 0, 33)<<endl;
}
