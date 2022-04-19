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
    TreeNode* a=NULL;
    TreeNode* b=NULL;
    TreeNode* c=NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    void dfs(TreeNode* root) {
        if(root==NULL) return ;
        dfs(root->left);
        if(prev!=NULL && prev->val > root->val) {
            if(a==NULL) {
                a = prev;
                b = root;
            }
            else {
                c = root;
            }
        }
        
        prev = root;
        dfs(root->right);
    }
    void recoverTree(TreeNode* root) {
        dfs(root);
        if(a && c) {swap(a->val,c->val);}
        else if(a && b) {
            swap(a->val,b->val);
        }
    }
};