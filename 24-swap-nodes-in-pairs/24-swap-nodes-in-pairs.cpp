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
        if(!head || !head->next) return head;
        ListNode* x = new ListNode(0);
        x->next = head;
        ListNode* y = x;
        while(head && head->next) {
            ListNode* newptr = head->next->next;
            y->next = head->next;
            head->next->next = head;
            y = head;
            y->next = newptr;
            head=newptr;
        }
        return x->next;
    }
};