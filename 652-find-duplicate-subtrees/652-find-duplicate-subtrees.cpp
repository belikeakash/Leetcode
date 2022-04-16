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
    vector<TreeNode*>v;
    string func(TreeNode* root, unordered_map<string,int>&m) {
        if(root==NULL) return "";
        string s = to_string(root->val);
        s+="$";
        s+=func(root->left,m);
        s+="$";
        s+=func(root->right,m);
        
        if(m[s]==1) v.push_back(root);
        m[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>m;
        func(root,m);
        for(auto x:m) cout<<x.first<<" ";
        return v;
    }
};