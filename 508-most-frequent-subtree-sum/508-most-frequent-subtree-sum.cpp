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
    int func(TreeNode* root, map<int,int>&m) {
        if(root==NULL) return 0;
        int old = root->val;
        int ans1 = func(root->left,m);
        int ans2 = func(root->right,m);
        int ans = ans1+ans2+old;
        m[ans]++;
        return ans;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int>m;
        func(root,m);
        vector<int>ans;
        int mini = 0;
        for(auto x:m) {
            if(x.second>mini) {
                mini = x.second;
            }
        }
        for(auto x:m) {
            if(x.second==mini) {
                ans.push_back(x.first);
            }
        }
        cout<<mini<<endl;
        return ans;
        
    }
};