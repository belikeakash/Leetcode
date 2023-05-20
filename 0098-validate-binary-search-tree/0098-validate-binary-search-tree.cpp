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
    #define ll long long
    bool func(TreeNode* root, long mini, long maxi){
        if(!root) return 1;
        if(root->val>maxi || root->val<mini) return 0;
        return func(root->left, (long)mini, (long)root->val-1) && func(root->right, (long)root->val+1, (long)maxi);
        
    }
    bool isValidBST(TreeNode* root) {
        return func(root, LONG_MIN, LONG_MAX);
    }
};