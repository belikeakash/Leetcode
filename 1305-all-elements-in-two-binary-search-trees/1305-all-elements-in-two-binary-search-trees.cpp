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
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*>s1,s2;
        vector<int>ans;
        while(!s1.empty() || !s2.empty() || root1 || root2) {
            while(root1!=NULL) {
                s1.push(root1);
                root1=root1->left;
            }
            while(root2!=NULL) {
                s2.push(root2);
                root2=root2->left;
            }
            if(s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val)) {
                ans.push_back(s1.top()->val);
                root1=s1.top()->right;
                s1.pop();
            }
            else {
                ans.push_back(s2.top()->val);
                root2=s2.top()->right;
                s2.pop();
            }
        }
        return ans;
    }
};