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
    void DFS(TreeNode* root, int val) {
        
        if(root->val < val) {
            if(root->right==NULL) {TreeNode* x = new TreeNode(val); root->right = x; return;}
            DFS(root->right,val);
        }
        else {
            if(root->left==NULL) {TreeNode* x = new TreeNode(val); root->left = x; return;}
            DFS(root->left,val);
        }
        // return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) {
            TreeNode* x = new TreeNode(val);
            return x;
        }
        DFS(root,val);
        
        return root;
    }
};