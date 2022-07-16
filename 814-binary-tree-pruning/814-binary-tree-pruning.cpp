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
    int func(TreeNode* root) {
        if(root==NULL) return 0;
        int x = func(root->left);
        int y = func(root->right);
        
        if(x==0) root->left = NULL;
        if(y==0) root->right = NULL;
        return (root->val==1) || (x||y);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
        int x = func(root);
        if(x==0) return NULL;
        return root;
    }
};