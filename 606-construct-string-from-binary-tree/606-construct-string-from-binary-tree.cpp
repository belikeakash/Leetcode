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
    void func(TreeNode* root, string& s) {
        if(root==NULL || (root->left == NULL && root->right == NULL)) return;
        if(root->left==NULL && root->right!=NULL) s+="()";
        if(root->left) {
            s = s + '(' + to_string(root->left->val);
            func(root->left,s);
            s+=')';
        }
        if(root->right) {
            s = s+ '(' + to_string(root->right->val);
            func(root->right,s);
            s+=')';
        }
         return;
    }
    string tree2str(TreeNode* root) {
        string s = "";
        s+=to_string(root->val);
        func(root,s);
        return s;
    }
};