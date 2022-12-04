/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*  slow = head;
        ListNode* fast = head;
        int cnt = 1e5+4;
        while(fast && fast->next && cnt--) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return 1;
        }
        return 0;
        
    }
};