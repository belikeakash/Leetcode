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
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q) return root;
        TreeNode* left = findLCA(root->left,p,q);
        TreeNode* right = findLCA(root->right,p,q);
        if(left==NULL) return right;
        else if(right==NULL) return left;
        else return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            v.clear();
            for(int i=0;i<n;i++) {
                auto x = q.front();
                v.push_back(x);
                q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        }
        
        return findLCA(root,v[0],v[v.size()-1]);
    }
};