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
    int res = INT_MIN;
    int func(TreeNode* root) {
        if(root==NULL) return 0;
        int a = max(func(root->left),0);
        int b = max(func(root->right),0);
        res = max(res,(a+b+root->val));
        return max(0,root->val+max(a,b));
    }
    int maxPathSum(TreeNode* root) {
        // if(root->left==NULL && root->right==NULL) return root->val;
        func(root);
        
        return res;
    }
};