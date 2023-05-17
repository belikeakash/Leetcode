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
    void func(TreeNode* root, string s, vector<string>&ans) {
        
        if(!root->left && !root->right) { s+=to_string(root->val); ans.push_back(s); return;}
        if(root->left) func(root->left, s+to_string(root->val)+"->", ans);
        if(root->right) func(root->right, s+to_string(root->val)+"->", ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        func(root, "", ans);
        
        return ans;
    }
};