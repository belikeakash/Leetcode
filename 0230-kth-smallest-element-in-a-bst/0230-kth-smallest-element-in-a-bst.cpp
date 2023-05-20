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
    int ans = -1;
    int x = 0;
    void func(TreeNode* root,int k) {
        if(!root) return;
        func(root->left, k);
        x++;
        if(x==k) {ans = root->val; return;}
        func(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        func(root,k);
        return ans;
    }
};