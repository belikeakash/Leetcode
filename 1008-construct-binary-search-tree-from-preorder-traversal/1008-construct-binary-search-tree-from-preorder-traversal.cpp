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
    TreeNode* func(vector<int>&p, int s, int e) {
        if(s>e) return NULL;
        if(s==e) {
            TreeNode* root = new TreeNode(p[s]);
            return root;
        }
        TreeNode* root = new TreeNode(p[s]);
        int i = s;
        for(i=s;i<=e;i++) {
            if(p[i]>p[s]) break;
        }
        root->left = func(p,s+1,i-1);
        root->right = func(p,i,e);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& p) {
        TreeNode* root = func(p,0,p.size()-1);
        return root;
    }
};