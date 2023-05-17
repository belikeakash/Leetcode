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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int, map<int, priority_queue<int, vector<int>, greater<int>>>>m;
        queue<pair<TreeNode*, pair<int, int>>>q;
        q.push({root, {0, 0}});
        
        while(!q.empty()) {
            auto x = q.front();
            q.pop();
            m[x.second.first][x.second.second].push({x.first->val});
            if(x.first->left) q.push({x.first->left, {x.second.first-1, x.second.second+1}});
            if(x.first->right) q.push({x.first->right, {x.second.first+1, x.second.second+1}});
        }
        
        for(auto x:m) {
            vector<int>v;
            for(auto &y: x.second) {
                while(!y.second.empty()) {
                    v.push_back(y.second.top());
                    y.second.pop();
                }
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};