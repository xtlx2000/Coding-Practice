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

int Search(int *a, int target, int num)
{
    for(int i = 0; i < num; i++){
        if(target == a[i]){
            return i;
        }
    }
    return -1;
}

struct TreeNode *concreate(int preorder[], int inorder[], int num,
                           int start, int end, struct TreeNode **parentPtr)
{
    //在inorder[start, end]中找出在preorder[]中第一个出现的数字，记录这个数字在inorder中的索引和值
    int root_index;
    //TODO
    //...


    struct TreeNode *tree = new (struct TreeNode);
    tree->set(inorder[root_index], NULL, NULL);

    concreate(preorder, inorder, num, start, root_index-1, &tree->left);
    concreate(preorder, inorder, num, root_index-1, end, &tree->right);

    return tree;
}

int main()
{
    int preorder[] = {10,5,1,8,6,9,15};
    int inorder[] = {1,5,6,8,9,10,15};

    struct TreeNode* tree = createTree(preorder, inorder, 7);
}
