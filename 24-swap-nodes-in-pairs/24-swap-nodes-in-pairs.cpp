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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp1 = head;
        if(!temp1) return head;
        ListNode* temp2 = head->next;
        if(!temp2) return head;
        ListNode* prev = NULL;
        head = head->next;
        while(temp1 && temp2) {
            if(prev) prev->next = temp2;
            temp1->next = temp2->next;
            temp2->next = temp1;
            prev = temp1;
            temp1 = temp1->next;
            if(temp1) temp2 = temp1->next;
        }
        return head;
    }
};