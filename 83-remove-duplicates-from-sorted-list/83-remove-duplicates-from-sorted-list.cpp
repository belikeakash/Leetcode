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
        if(head==NULL || head->next==NULL) return head;
        ListNode* a = head;
        ListNode* b = head->next;
        while(b!=NULL) {
            if(b->val==a->val) {
                ListNode* c = b;
                a->next = c->next;
                b = c->next;
                c->next = NULL;
            }
            else {
                a = b;
                b = b->next;
            }
        }
        return head;
    }
};