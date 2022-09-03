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
    int ans = 0;
    bool func(TreeNode* r1, TreeNode* r2) {
        if(r1==NULL && r2==NULL) return 1;
        if(r1==NULL && r2!=NULL) return 0;
        if(r2==NULL && r1!=NULL) return 0;
        if(r1!=NULL && r2!=NULL && r1->val != r2->val) return 0;
        return func(r1->left,r2->left) && func(r1->right,r2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return 0;
        if(root->val==subRoot->val) {
            ans = ans || func(root,subRoot);
        }
        isSubtree(root->left,subRoot);
        isSubtree(root->right,subRoot);
        return ans;
    }
};