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
    void func(TreeNode* root, vector<int>&a) {
        if(root==NULL) return;
        func(root->left,a);
        a.push_back(root->val);
        func(root->right,a);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>a;
        func(root,a);
        int ans = INT_MAX;
        for(int i=1;i<a.size();i++) {
            ans = min(ans,a[i]-a[i-1]);
        }
        return ans;
    }
};