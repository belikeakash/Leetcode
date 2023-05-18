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
    void func(TreeNode* root, TreeNode* &head) {
        if(!root) return;
        cout<<root->val<<" ";
        head->right = root;
        head = head->right;
        auto l = root->left;
        auto r = root->right;
        head->left= NULL;
        head->right = NULL;
        if(l) {func(l, head);}
        //head->left = NULL;
        if(r) func(r, head);
        //head->right = NULL;
        cout<<"s";
        //root->right = NULL;
        //root->left = NULL;
        
    }
    void flatten(TreeNode* root) {
        TreeNode* head = new TreeNode(-1);
        head->left = NULL;
        head->right = NULL;
        TreeNode* temp = head;
        func(root, temp);
        temp->right = NULL;
        root = temp->right;
    }
};