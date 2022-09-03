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
    
    void func(TreeNode* root, vector<int>&v, int i) {
        if(root==NULL) return;
        if(i==v.size()) v.push_back(root->val);
        if(root->right) func(root->right,v,i+1);
        if(root->left) func(root->left,v,i+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        func(root,v,0); 
        return v;
    }
};