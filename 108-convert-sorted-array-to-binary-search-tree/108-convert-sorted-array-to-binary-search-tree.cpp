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
    TreeNode* func(vector<int>&a, int s, int e) {
        if(s>e) return NULL;
        int mid = (s + e)/2;
        TreeNode* root = new TreeNode(a[mid]);
        root->left = func(a,s,mid-1);
        root->right = func(a,mid+1,e);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& a) {
        int n = a.size();
        TreeNode* root = func(a,0,n-1);
        return root;
    }
};