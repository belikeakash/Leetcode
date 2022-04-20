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
    TreeNode* ans;
    void func(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* dummy = root;
        while(root!=NULL) {
            if(p->val <= root-> val && q->val >= root->val) {
                ans = root;
                break;
            }
            else if(p->val > root->val) {
                root=root->right;
            }
            else {
                root=root->left;
            }
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(p->val > q->val) {
            func(root,q,p);
        }
        else func(root,p,q);
        return ans;
    }
};