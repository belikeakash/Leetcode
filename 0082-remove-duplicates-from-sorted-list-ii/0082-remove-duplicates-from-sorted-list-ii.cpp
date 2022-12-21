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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* dummy = new ListNode(-1);
        // dummy->next = head;
        ListNode* temp = dummy;
        bool flag = 0;
        while(fast) {
            if(fast->val==slow->val) {
                fast=fast->next;
                flag = 1;
            }
            else {
                // slow->next = fast;
                // slow=fast;
                // fast=fast->next;
                
                if(flag) {
                    slow=fast;
                    fast=fast->next;
                }
                else {
                    temp->next = slow;
                    temp=temp->next;
                    temp->next = NULL;
                    slow=fast;
                    fast=fast->next;
                }
                flag = 0;
            }
        }
        // slow->next = NULL;
        if(temp->val!=slow->val && !flag) temp->next = slow;
        slow->next = NULL;
        return dummy->next;
    }
};