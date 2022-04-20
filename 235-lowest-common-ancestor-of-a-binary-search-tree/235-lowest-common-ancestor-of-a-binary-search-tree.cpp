/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void Traverse(TreeNode* root, TreeNode* x,vector<TreeNode*>&v) {
        if(root==NULL) return;
        TreeNode* nroot = root;
        while(root!=NULL) {
            v.push_back(nroot);
                if(nroot->val==x->val){
                break; }
            else if(nroot->val > x->val) {
                nroot=nroot->left;
            }
            else {
                nroot=nroot->right;
            }
        }
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>v1,v2;
        Traverse(root,p,v1);
        Traverse(root,q,v2);
        TreeNode* ans;
        for(auto x:v1) {
            cout<<x->val<<" ";
        }
        cout<<endl;
        for(auto x:v2) {
            cout<<x->val<<" ";
        }
        for(int i=0;i<min(v1.size(),v2.size());i++) {
            if(v1[i]->val==v2[i]->val) ans = v1[i];
            else break;
        }
        return ans;
    }
};