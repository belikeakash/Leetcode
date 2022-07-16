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
        int x = -1;
        int pos = -1;
        for(int i=s;i<=e;i++) {
            if(a[i]>x) {
                x = a[i];
                pos = i;
            }
        }
        TreeNode* root = new TreeNode(x);
        root->left = func(a,s,pos-1);
        root->right = func(a,pos+1,e);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& a) {
        int n = a.size();
        return func(a,0,n-1);
    }
};