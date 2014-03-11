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

int HeightGap(struct TreeNode *root);
bool isBalanced(struct TreeNode *root)
{
    return HeightGap(root) > 1;
}

int HeightGap(struct TreeNode *root)
{
    if(root == NULL){
        return 0;
    }

    int left = HeightGap(root->left);
    int right = HeightGap(root->right);
    int gap = abs(left - right);
    if(gap > 1){
        return -1;
    }

    if(left == -1 || right == -1){//¼ôÖ¦
        return -1;
    }

    return max(left, right)+1;
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

    cout << isBalanced(tree) <<endl;
    cout << isBalanced(tmp1) <<endl;
}
