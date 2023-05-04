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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return 1;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = head;
        while(fast && fast->next) {
            temp = slow;
            slow = slow->next;
            fast=fast->next->next;
        }
        ListNode* a;
        ListNode* b;
        if(fast){
            a = head;
            b = slow->next;
            temp->next = NULL;
        }
        else {
            a = head;
            b = slow;
            temp->next = NULL;
        }
        // cout<<"A-> ";
        // while(a) {
        //     cout<<a->val<<" ";
        //     a=a->next;
        // }
        // cout<<"B-> ";
        
        b = reverse(b);
        // while(b) {
        //     cout<<b->val<<" ";
        //     b=b->next;
        // }
        // cout<<endl;
        while(a && b) {
            //cout<<a->val<<" "<<b->val<<endl;
            if(a->val!=b->val) return 0;
            a=a->next;
            b=b->next;
        }
        return 1;
    }
};