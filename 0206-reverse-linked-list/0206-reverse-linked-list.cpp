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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* dummy = new ListNode(-5003);
        ListNode* temp1 = head;
        dummy->next = head;
        
        ListNode* t2 = head;
        ListNode* t3 = dummy;
        while(temp1) {
            t2 = temp1->next;
            temp1->next = t3;
            dummy->next = t2;
            t3 = temp1;
            temp1 = t2;
            // cout<<t3->val<<" ";
        }
        
        head = t3;
        ListNode* temp = head;
        if(temp->next==NULL) return NULL;
        while(temp->next->val!=-5003) {
            temp=temp->next;
        }
        // return head;
        temp->next = NULL;
        return head;
        
    }
};