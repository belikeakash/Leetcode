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
    int i = 0;
    int ans;
    void func(TreeNode* root, int k) {
        if(root->left) func(root->left,k);
        i++;
        cout<<i<<" ";
        if(i==k) {
            // cout<<i<<" ";
            ans = root->val;
            return;
        }
        if(root->right) func(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return -1;
        func(root,k);
        return ans;
    }
};