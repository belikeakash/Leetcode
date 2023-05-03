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
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* a = head;
        ListNode* b = head->next;
        while(a && b) {
            a->next = b->next;
            b->next = head;
            head = b;
            b = a->next;
        }
        return head;
    }
    ListNode* removeNodes(ListNode* head) {
    if(!head->next) return head;    
    head = reverse(head);
    int maxi = 0;
    ListNode* a = head->next;
    ListNode* b = head;
    maxi = b->val;
    while(a) {
        if(a->val>=maxi) {
            b->next = a;
            b = a;
            maxi = max(maxi,a->val);
        }
        a=a->next;
    }
    b->next = NULL;
    return reverse(head);
    }
};