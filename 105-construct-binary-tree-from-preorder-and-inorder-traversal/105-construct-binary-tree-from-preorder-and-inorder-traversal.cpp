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
    TreeNode* func(int i,int j,vector<int>& pr, vector<int>& in, int s, int e) {
        if(s>e || i>j) return NULL;
        TreeNode* root = new TreeNode(pr[i]);
        int p = 0;
        for(p=s;p<=e;p++) {
            if(in[p]==pr[i]) break;
        }
        root->left = func(i+1,i+p-s,pr,in,s,p-1);
        root->right = func(i+p+1-s,j,pr,in,p+1,e);
        return root;
    }
    TreeNode* buildTree(vector<int>& pr, vector<int>& in) {
        return func(0,pr.size()-1,pr,in,0,in.size()-1);
        
    }
};