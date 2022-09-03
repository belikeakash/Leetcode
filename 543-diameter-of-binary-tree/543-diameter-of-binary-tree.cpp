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
    int ans = 0;
    int func(TreeNode* root) {
        if(root==NULL) return 0;
        int l = func(root->left);
        int r = func(root->right);
        return 1 + max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int l = func(root->left);
        int r = func(root->right);
        ans = max(ans,l+r);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return ans;
    }
};