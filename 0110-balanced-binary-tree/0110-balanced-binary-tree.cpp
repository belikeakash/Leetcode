/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int func(TreeNode* root, bool &flag) {
        if(!root) return 0;
        int l = func(root->left, flag);
        int r = func(root->right, flag);
        if(abs(l-r)>1) flag = 0;
        return 1 + max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        bool flag = 1;
        func(root, flag);
        return flag;
    }
};