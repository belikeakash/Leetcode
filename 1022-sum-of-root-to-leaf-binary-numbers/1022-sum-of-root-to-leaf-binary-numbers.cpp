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
    void func(TreeNode* root, int x) {
        if(root==NULL) return; 
        if(root->left==NULL && root->right==NULL) {ans+=x*2 + root->val; return;} 
        func(root->left,2*x + root->val);
        func(root->right,2*x + root->val);
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL) return 0;
        func(root,0);
        return ans;
    }
};