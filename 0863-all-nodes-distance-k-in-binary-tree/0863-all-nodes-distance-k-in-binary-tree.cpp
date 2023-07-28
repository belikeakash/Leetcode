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
    unordered_map<TreeNode*, TreeNode*>m;
    void makeMap(TreeNode* root) {
        if(!root) return;
        if(root->left) m[root->left] = root;
        if(root->right) m[root->right] = root;
        makeMap(root->left);
        makeMap(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        makeMap(root);
        vector<int>ans;
        if(k==0) {ans.push_back(target->val); return ans;}
        queue<TreeNode*>q;
        unordered_map<TreeNode*, int>vis;
        vis[target] = 1;
        q.push(target);
        int cnt=0;
        while(!q.empty()) {
            cnt++;
            int n = q.size();
            for(int i=0;i<n;i++) {
                auto x = q.front();
                q.pop();
                if(x->left && !vis[x->left]) {
                    q.push(x->left);
                    vis[x->left] = 1;
                }
                if(x->right && !vis[x->right]) {
                    q.push(x->right);
                    vis[x->right] = 1;
                }
                if(m[x] && !vis[m[x]]) {
                    q.push(m[x]);
                    vis[m[x]] = 1;
                }
            }
            if(cnt==k) break;
        }
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};