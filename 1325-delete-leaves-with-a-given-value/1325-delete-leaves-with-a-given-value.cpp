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
    bool isValid(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        return 0;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int x) {
        if(isValid(root)) {
            if(root->val==x) return NULL;
        }
        if(root->left)root->left = removeLeafNodes(root->left,x);
        if(root->right)root->right = removeLeafNodes(root->right,x);
        if(isValid(root)) {
            if(root->val==x) return NULL;
        }
        return root;
    }
};