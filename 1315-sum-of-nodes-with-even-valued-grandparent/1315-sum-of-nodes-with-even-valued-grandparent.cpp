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
    void DFS(TreeNode* root, map<TreeNode*,TreeNode*>&m) {
        if(root->left) {
            m[root->left] = root;
            DFS(root->left,m);
        }
        if(root->right) {
            m[root->right] = root;
            DFS(root->right,m);
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        map<TreeNode*, TreeNode*>m;
        m[root] = NULL;
        DFS(root,m);
        int ans = 0;
        queue<TreeNode*>q;
        int level = 1;
        q.push(root);
        // for(auto x:m) {
        //     if(x.first==root) continue;
        //     cout<<x.second->val<<" ";
        // }
        while(!q.empty()) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                auto x = q.front();
                if(level>=3) {
                    
                    int u =  m[m[x]]->val;
                    cout<<u<<" ";
                    if(u%2==0) {
                        ans += x->val;
                    }
                }
                q.pop();
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
                
            }
            level++;
        }
        return ans;
    }
};