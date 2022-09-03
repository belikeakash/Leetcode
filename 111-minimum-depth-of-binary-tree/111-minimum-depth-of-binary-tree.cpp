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
    bool isLeaf(TreeNode* root) {
        if(!root->left && !root->right) return 1;
        return 0;
    }
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int ans = 0;
        while(!q.empty()) {
            ans++;
            int n = q.size();
            for(int i=0;i<n;i++) {
                auto x = q.front();
                q.pop();
                if(isLeaf(x)) {
                    return ans;
                }
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        }
        return ans;
    }
};