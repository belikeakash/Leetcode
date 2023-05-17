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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
        queue<TreeNode*>q;
        vector<int>v;
        bool flag = 0;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()) {
            int sz= q.size();
            for(int i=0;i<sz;i++) {
                auto x = q.front();
                q.pop();
                v.push_back(x->val);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            
            if(!flag) {
                flag = !flag;
                ans.push_back(v);
            }
            else {
                flag = !flag;
                reverse(v.begin(), v.end());
                ans.push_back(v);
            }
            v.clear();
        }
        
        return ans;
    }
};