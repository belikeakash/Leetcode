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
    TreeNode* ans = NULL;
    int func(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return 0;
        int x = 0;
        if(root->val==p->val) x+= 1;
        if(root->val==q->val) x+= 1;
        
        x += func(root->left, p, q) + func(root->right, p, q);
        if(x==2 && !ans) ans = root;
        return x;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        func(root, p, q);
        return ans;
    }
};