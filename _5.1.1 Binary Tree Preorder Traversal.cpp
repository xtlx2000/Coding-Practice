#include <iostream>
#include <stack>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

//1 recursion
//1.1 preorder
//1.2 inorder
//1.3 postorder

//2 iteration
//2.1 preorder
//2.2 inorder
//2.3 postorder

//3 LevelOrder


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

void traverse(struct TreeNode *tree)
{
    cout <<tree->value<< " ";
}

//1.1 preorder
void preorder_recursion(struct TreeNode *tree, void (*func)(struct TreeNode *t))
{
    if(tree == NULL){
        return;
    }

    func(tree);
    preorder_recursion(tree->left, func);
    preorder_recursion(tree->right, func);
}
//1.2 inorder
void inorder_recursion(struct TreeNode *tree, void (*func)(struct TreeNode *t))
{
    if(tree == NULL){
        return;
    }

    inorder_recursion(tree->left, func);
    func(tree);
    inorder_recursion(tree->right, func);
}
//1.3 postorder
void postorder_recursion(struct TreeNode *tree, void(*func)(struct TreeNode *t))
{
    if(tree == NULL){
        return;
    }

    postorder_recursion(tree->left, func);
    postorder_recursion(tree->right, func);
    func(tree);
}

//2.1 preorder
void preorder_iteration(struct TreeNode *tree, void(*func)(struct TreeNode *t))
{
    if(tree == NULL){
        return;
    }

    stack<struct TreeNode *> stackTraverse;

    struct TreeNode *ptr = tree;
    stackTraverse.push(ptr);

    while(!stackTraverse.empty()){
        ptr = stackTraverse.top();
        stackTraverse.pop();

        func(ptr);

        if(ptr->right){
            stackTraverse.push(ptr->right);
        }
        if(ptr->left){
            stackTraverse.push(ptr->left);
        }


    }
}
//2.2 inorder
void inorder_iteration(struct TreeNode *tree, void(*func)(struct TreeNode *t))
{
    if(tree == NULL){
        return;
    }
    stack<struct TreeNode *> stackTraverse;

    struct TreeNode *ptr = tree;

    while(!stackTraverse.empty() || ptr){

        if(ptr){
            stackTraverse.push(ptr);
            ptr = ptr->left;
        }else{
            ptr = stackTraverse.top();
            stackTraverse.pop();

            func(ptr);
            ptr = ptr->right;
        }
    }
}
//2.3 postorder
void postorder_iteration(struct TreeNode *tree, void(*func)(struct TreeNode *t))
{
    if(tree == NULL){
        return;
    }
    stack<struct TreeNode *> stackTraverse;
    map<struct TreeNode*, bool> isVisited;

    struct TreeNode *ptr = tree;

    while(!stackTraverse.empty() || ptr){

        if(ptr){
            stackTraverse.push(ptr);
            ptr = ptr->left;
        }else{
            ptr = stackTraverse.top();
            if(ptr->right && !isVisited[ptr->right]){
                isVisited[ptr->right] = true;
                ptr = ptr->right;
            }else{
                stackTraverse.pop();
                func(ptr);
                ptr = NULL;
            }
        }
    }
}

//3 Level Order
void levelorder(struct TreeNode *tree, void(*func)(struct TreeNode*))
{
    if(tree == NULL){
        return;
    }
    queue<struct TreeNode *> queueTraverse;

    struct TreeNode *ptr = tree;
    queueTraverse.push(ptr);

    while(!queueTraverse.empty()){

        ptr = queueTraverse.front();
        queueTraverse.pop();
        func(ptr);

        if(ptr->left){
            queueTraverse.push(ptr->left);
        }
        if(ptr->right){
            queueTraverse.push(ptr->right);
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

    preorder_recursion(tree, traverse);cout<<endl;
    inorder_recursion(tree, traverse);cout<<endl;
    postorder_recursion(tree, traverse);cout<<endl;

    preorder_iteration(tree, traverse);cout<<endl;
    inorder_iteration(tree, traverse);cout<<endl;
    postorder_iteration(tree, traverse);cout<<endl;

    levelorder(tree, traverse);cout<<endl;
}
