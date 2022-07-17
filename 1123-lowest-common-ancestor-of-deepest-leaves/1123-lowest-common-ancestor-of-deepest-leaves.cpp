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
        return max((1+func(root->left)),(1+func(root->right)));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL) return root;
        int l = func(root->left);
        int r = func(root->right);
        if(l==r) {
            return root;
        }
        else if(l<r) {
            return lcaDeepestLeaves(root->right);
        }
        else {
            return lcaDeepestLeaves(root->left);
        }
    }
};