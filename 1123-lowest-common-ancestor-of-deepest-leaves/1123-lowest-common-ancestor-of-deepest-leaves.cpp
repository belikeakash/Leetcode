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
    void DFS(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&m) {
        if(root==NULL) return;
        if(root->left) {
            m[root->left] = root;
            DFS(root->left,m);
        }
        if(root->right) {
            m[root->right] = root;
            DFS(root->right,m);
        }
    }
    void func(TreeNode* root, unordered_map<TreeNode*,int>m, TreeNode* &ans, int n) {
        if(root==NULL) return;
        if(m[root]==n) {
            ans = root;
        }
        if(root->left) {
            func(root->left,m,ans,n);
        }
        if(root->right) {
            func(root->right,m,ans,n);
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            v.clear();
            for(int i=0;i<n;i++) {
                auto x = q.front();
                v.push_back(x);
                q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        }
        
        unordered_map<TreeNode*,TreeNode*>m1;
        m1[root] = NULL;
        DFS(root,m1);
        unordered_map<TreeNode*,int>m2;
        for(int i = 0;i<v.size();i++) {
            auto x = v[i];
            // cout<<x->val<<" ";
            while(x!=NULL) {
                m2[x]++;
                x = m1[x];
                
            }
            
        }
        
        int maxi = 0;
        TreeNode* ans = NULL;
        for(auto x:m2) {
            if(x.second==v.size()) {
                maxi = x.second;
                ans = x.first;
                // cout<<ans->val<<" ";
            }
            cout<<x.first->val<<"->"<<x.second<<"  ";
        }
        func(root,m2,ans,v.size());
        cout<<endl;
        return ans;;
    }
};