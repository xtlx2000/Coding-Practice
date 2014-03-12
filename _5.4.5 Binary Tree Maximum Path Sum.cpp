#include <iostream>
#include <algorithm>
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

int maxSum = 0;
int maxPathSum(struct TreeNode *root)
{
    if(root == NULL){
        return 0;
    }

    int max_left = maxPathSum(root->left);
    int max_right = maxPathSum(root->right);

    int tmpMaxSum = max_left + max_right + root->value;

    maxSum = max(maxSum, tmpMaxSum);

    return max_left > max_right ? max_left+root->value : max_right+root->value;
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

    cout <<maxPathSum(tmp5)<<endl;
    cout <<maxPathSum(tmp6)<<endl;
    cout <<maxPathSum(tmp4)<<endl;
    cout <<maxPathSum(tmp1)<<endl;
    cout <<maxPathSum(tmp2)<<endl;

    maxSum = 0;
    maxPathSum(tree);
    cout <<maxSum<<endl;
}
