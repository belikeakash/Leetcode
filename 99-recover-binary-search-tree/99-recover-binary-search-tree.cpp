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
    void DFS(TreeNode* root, vector<TreeNode*>&v, vector<TreeNode*>&p) {
        if(root==NULL) return;
        if(root->left) DFS(root->left,v,p);
        v.push_back(root);
        p.push_back(root);
        if(root->right) DFS(root->right,v,p);
    }
    static bool comp(TreeNode* a, TreeNode* b) {
        return a->val<b->val;
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>v;
        vector<TreeNode*>p;
        DFS(root,v,p);
        TreeNode* a;
        TreeNode* b;
        sort(v.begin(),v.end(),comp);
        for(auto x:v) {
            cout<<x->val<<" ";
        }
        cout<<endl;
        int n = v.size();
        for(int i=0;i<n;i++) {
            if(v[i]->val != p[i]->val) {
                int i1 = p[i]->val;
                int i2 = v[i]->val;
                v[i]->val = i1;
                p[i]->val = i2;
                break;
            }
        }
    }
};