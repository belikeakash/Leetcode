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
    void BFS(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&m) {
        if(root==NULL) return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                auto x = q.front();
                q.pop();
                if(x->left) {
                    m[x->left] = x;
                    q.push(x->left);
                }
                if(x->right) {
                    m[x->right] = x;
                    q.push(x->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k) {
        vector<int>ans;
        if(root==NULL) return ans;
        unordered_map<TreeNode*, TreeNode*>m;
        BFS(root,m);
        queue<TreeNode*>q;
        q.push(t);
        int u = -1;
        map<TreeNode*,int>vis;
        vis[t]=1;
        while(!q.empty()) {
            if(u==k) break;
            u++;
            int n = q.size();
            for(int i=0;i<n;i++) {
                auto x = q.front();
                q.pop();
                if(u==k) ans.push_back(x->val);
                if(x->left && vis[x->left]!=1) {q.push(x->left); vis[x->left]=1;}
                if(x->right && vis[x->right]!=1) {q.push(x->right); vis[x->right]=1;}
                if(m[x] && vis[m[x]]!=1) {q.push(m[x]); vis[m[x]]=1;}
            }
        }
        // while(!q.empty()) {
        //     ans.push_back(q.front()->val);
        //     q.pop();
        // }
        return ans;
    }
};