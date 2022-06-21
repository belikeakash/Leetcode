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
    TreeNode* constructMaximumBinaryTree(vector<int>& a) {
        if(a.size()==0) return NULL;
        priority_queue<int>q;
        for(auto x:a) {
            q.push(x);
        }
        int u = q.top();
        TreeNode* root = new TreeNode(u);
        vector<int>x1,x2;
        int i = 0;
        // int n = a.size();
        for(i=0;i<a.size();i++) {
            if(a[i]!=u) x1.push_back(a[i]);
            else break;
        }
        for(int j = i+1;j<a.size();j++) x2.push_back(a[j]);
        for(auto x:x2) cout<<x<<" ";
        root->left = constructMaximumBinaryTree(x1);
        root->right = constructMaximumBinaryTree(x2);
        return root;
    }
};