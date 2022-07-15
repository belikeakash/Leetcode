/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head==NULL) return NULL;
        
        ListNode* a = head;
        ListNode* b = head;
        ListNode* prev = NULL;
        while(b && b->next) {
            prev = a;
            a=a->next;
            b = b->next->next;
        }
        if(prev==NULL) {
            TreeNode* x = new TreeNode(head->val);
            return x;
        }; 
        prev->next = NULL;
        TreeNode* root = new TreeNode(a->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(a->next);
        return root;
    }
};