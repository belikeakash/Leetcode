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
    #define ll long long
    ll cnt = 0;
    void DFS(TreeNode* root, int x, ll sum) {
        if(root==NULL) return;
        sum+=root->val;
        if(root->left) {
            DFS(root->left,x,sum);
        }
        if(root->right) {
            DFS(root->right, x, sum);
        }
        if(sum==x) cnt++;
        sum-=root->val;
    }
    void st(TreeNode* root, int x) {
        if(root==NULL) return;
        ll sum = 0;
        DFS(root,x,sum);
        if(root->left) {
            st(root->left,x);
        }
        if(root->right) {
            st(root->right,x);
        }
    }
    int pathSum(TreeNode* root, int x) {
        st(root,x);
        return cnt;
    }
};