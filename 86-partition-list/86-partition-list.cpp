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
        ListNode* a = new ListNode(INT_MIN);
        ListNode* ref = a;
        ListNode* temp = head;
        while(temp) {
            if(temp->val<x) {
                ref->next = new ListNode(temp->val);
                ref=ref->next;
            }
            temp=temp->next;
        }
        temp = head;
        while(temp) {
            if(temp->val>=x) {
                ref->next = new ListNode(temp->val);
                ref=ref->next;
            }
            temp=temp->next;
        }
        return a->next;
    }
};