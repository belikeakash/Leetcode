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
    vector<ll>v;
    void func(TreeNode* root, ll sum) {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) {
            sum = sum*10 + root->val;
            v.push_back(sum);
            return;
        }
        func(root->left,sum*10 + root->val);
        func(root->right,sum*10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
        func(root,0);
        ll ans = 0;
        for(auto x:v) ans+=x;
        return ans;
    }
};