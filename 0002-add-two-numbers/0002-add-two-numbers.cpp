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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int carry = 0;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* prev1 = l1;
        ListNode* prev2 = l2;
        while(l1 && l2) {
            sum=l1->val + l2->val + carry;
            if(sum>9) carry = 1;
            else carry = 0;
            sum = sum%10;
            l1->val = sum;
            l2->val = sum;
            prev1 = l1;
            prev2 = l2;
            l1=l1->next;
            l2=l2->next;
            
        }
        int p = 0;
        while(l1) {
            sum = l1->val + carry;
            if(sum>9) carry = 1;
            else carry = 0;
            sum = sum%10;
            l1->val = sum;
            p = 1;
            prev1 = l1;
            l1=l1->next;
        }
        while(l2) {
            sum = l2->val + carry;
            if(sum>9) carry = 1;
            else carry = 0;
            sum = sum%10;
            l2->val = sum;
            p = 2;
            prev2 = l2;
            l2=l2->next;
        }
        if(p==1) {
            cout<<carry<<" ";
            if(carry>0) {
                ListNode* op = new ListNode(carry);
                prev1->next = op;
                op->next = NULL;
            }
            return t1;
        }
        
        else {
            cout<<carry<<" ";
            if(carry>0) {
                ListNode* op = new ListNode(carry);
                prev2->next = op;
                op->next = NULL;
            }
            return t2;
        }
    }
};