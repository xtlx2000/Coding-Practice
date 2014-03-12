#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int value;
    struct TreeNode *left, *right;
    struct TreeNode *next;

    void set(int value_, struct TreeNode *left_, struct TreeNode *right_)
    {
        this->value = value_;
        this->left = left_;
        this->right = right_;
    }
};


// 1    递归迭代中序遍历   时间O(n)   空间O(n)
static queue<struct TreeNode*> queueOrder;
struct TreeNode *flatten_common_inorder(struct TreeNode *tree);
// 2    线索化中序遍历     时间O(n)   空间O(1)
struct TreeNode *flatten_thread_inorder(struct TreeNode *tree);

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

    struct TreeNode *ptr = flatten_common_inorder(tree);
    while(ptr){
        cout <<ptr->value<<"->";
        ptr = ptr->next;
    }
    cout<<endl;
}

// 1    递归迭代中序遍历   时间O(n)   空间O(n)
void common_inorder(struct TreeNode *tree)
{
    if(tree == NULL){
        return;
    }
    common_inorder(tree->left);
    queueOrder.push(tree);
    common_inorder(tree->right);
}
struct TreeNode *flatten_common_inorder(struct TreeNode *tree)
{
    common_inorder(tree);
    struct TreeNode *head = queueOrder.front();

    while(!queueOrder.empty()){
        struct TreeNode *ptr = queueOrder.front();
        queueOrder.pop();
        if(!queueOrder.empty()){
            ptr->next = queueOrder.front();
        }else{
            ptr->next = NULL;
        }
    }

    return head;
}
