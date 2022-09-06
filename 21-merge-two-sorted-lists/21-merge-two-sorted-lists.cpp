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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l2) return l1;
        if(!l1) return l2;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* ans;
        if(temp1->val < temp2->val) {ans=temp1; temp1=temp1->next;}
        else {ans=temp2; temp2=temp2->next;}
        ListNode* dummy = ans;
        while(temp1 && temp2) {
            if(temp1->val < temp2->val) {ans->next=temp1; temp1=temp1->next;}
            else {ans->next=temp2; temp2=temp2->next;}
            ans = ans->next;
        }
        if(temp1) ans->next = temp1;
        if(temp2) ans->next = temp2;
        
        return dummy;
    }
};