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
    vector<vector<int>>ans;
    vector<int>v;
    void func(TreeNode* root, int x, int &sum) {
        
        if(root==NULL) {
            return;
        }
        v.push_back(root->val);
        sum+=root->val;
        if(root->left == NULL && root->right == NULL) {
            if(sum==x) ans.push_back(v);
            
        }
        func(root->left,x,sum);
        func(root->right,x,sum);
        v.pop_back();
        sum-=root->val;
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int x) {
        vector<vector<int>> op;
        if(root==NULL) return op;
        int sum = 0;
        func(root,x,sum);
        
        // for(auto x:ans) {
        //     op.push_back(x);
        // }
        return ans;
    }
};