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
    TreeNode* getTargetCopy(TreeNode* t1, TreeNode* t2, TreeNode* x) {
        if(t1==NULL) return NULL;
        if(t1==x) return t2;
        auto p = getTargetCopy(t1->left,t2->left,x) ;
        auto q = getTargetCopy(t1->right,t2->right,x);
        if(p!=NULL) return p;
        return q;
    }
};