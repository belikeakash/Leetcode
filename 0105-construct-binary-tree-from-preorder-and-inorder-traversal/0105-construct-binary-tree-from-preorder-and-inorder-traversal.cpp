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
    TreeNode* func(int &k, vector<int>& pre, vector<int>& in, unordered_map<int,int>&m, int s, int e) {
        if(s>e) return NULL;
        cout<<s<<" "<<e<<" "<<pre[k]<<endl;
        if(s==e) {
            TreeNode* root = new TreeNode(pre[k]);
            k++;
            return root;
        }
        TreeNode* root = new TreeNode(pre[k]);
        int pos = m[pre[k]];
        k++;
        cout<<pos<<endl;
       // cout<<s<<" "<<pos-1<<endl;
        root->left = func(k, pre, in, m, s, pos-1);
       // cout<<pos+1<<" "<<e<<endl;
        //k++;
        root->right = func(k, pre, in, m, pos+1, e);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int,int>m;
        for(int i=0;i<pre.size();i++) {
            m[in[i]] = i;
        }
        int k = 0;
        return func(k, pre, in, m, 0, pre.size()-1);
    }
};