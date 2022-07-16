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
    void DFS(TreeNode* root, vector<int>& a) {
        if(root==NULL) return ;
        if(root->left) DFS(root->left,a);
        a.push_back(root->val);
        if(root->right) DFS(root->right,a);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2,ans;
        DFS(root1,v1);
        DFS(root2,v2);
        int i = 0,j=0;
        while(i<v1.size() && j<v2.size()) {
            if(v1[i]<v2[j]) {ans.push_back(v1[i]); i++;}
            else {ans.push_back(v2[j]); j++;}
        }
        while(i<v1.size()) {
            ans.push_back(v1[i]);
            i++;
        }
        while(j<v2.size()) {
            ans.push_back(v2[j]);
            j++;
        }
        return ans;
    }
};