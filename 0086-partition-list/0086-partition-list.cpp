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
        ListNode* d1 = new ListNode(-1);
        ListNode* d2 = new ListNode(-1);
        ListNode* dt1 = d1;
        ListNode* dt2 = d2;
        ListNode* temp = head;
        while(temp) {
            if(temp->val<x) {
                dt1->next = temp;
                temp=temp->next;
                dt1=dt1->next;
                dt1->next = NULL;
            }
            else {
                dt2->next = temp;
                temp=temp->next;
                dt2=dt2->next;
                dt2->next = NULL;
            }
        }
        dt1 = d1;
        while(dt1->next) {
            dt1=dt1->next;
        }
        dt1->next = d2->next;
        return d1->next;
    }
};