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
    ListNode* partition(ListNode* head, int x) {
        ListNode *temp1 = new ListNode(-1);
        ListNode *temp2 = new ListNode(-1);
        ListNode *p = temp1;
        ListNode *q = temp2;
        ListNode *temp = head;
        while(head) {
            if(head->val<x) {
                temp1->next = head;
                temp1=temp1->next;
            }
            else {
                temp2->next = head;
                temp2=temp2->next;
            }
            head=head->next;
        }
        temp2->next = NULL;
        temp1->next = q->next;
        
        return p->next;
    }
};