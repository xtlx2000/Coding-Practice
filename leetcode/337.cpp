/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    std::map<TreeNode*, int> mMap;
public:
    int findMaxRob(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        std::map<TreeNode*, int>::iterator iter = mMap.find(root);
        if (iter != mMap.end())
        {
            return iter->second;
        }
        return rob(root);
    }
    int rob(TreeNode* root) {
        // end condition
        if (root == NULL)
        {
            return 0;
        }
        // didvide
        int maxRob1 = root->val;
        int maxRob2 = 0;
        if (root->left){
            if (root->left->left) {
                maxRob1 += findMaxRob(root->left->left);
            }
            if (root->left->right) {
                maxRob1 += findMaxRob(root->left->right);
            }
            maxRob2 += findMaxRob(root->left);
        }
        if (root->right)
        {
            if (root->right->left) {
                maxRob1 += findMaxRob(root->right->left);
            }
            if (root->right->right){
                maxRob1 += findMaxRob(root->right->right);
            }
            maxRob2 += findMaxRob(root->right);
        }
        // conquer
        int mmaxRob =  max(maxRob1, maxRob2);
        mMap[root] = mmaxRob;
        return mmaxRob;
    }
};