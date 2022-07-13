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
        ListNode* slow = head;
        ListNode* fast = head;
        int c = 10009;
        while(c--) {
            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
                if(slow==fast) return 1;
            }
        }
        return 0;
    }
};