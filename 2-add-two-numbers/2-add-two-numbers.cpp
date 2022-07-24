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
    ListNode* func(ListNode* l1, ListNode* l2) {
        int c = 0;
        auto temp1 = l1;
        auto temp2 = l2;
        ListNode* p = NULL;
        // cout<<temp1->val;
        while(temp1!=NULL && temp2!=NULL) {
            temp1->val = temp1->val + temp2->val + c;
            
            c = temp1->val / 10;
            temp1->val = temp1->val % 10;
            cout<<temp1->val<<" ";
            p = temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        while(temp1!=NULL) {
            temp1->val = temp1->val + c;
            c = temp1->val/10;
            temp1->val = temp1->val % 10;
              cout<<temp1->val<<" ";
            p = temp1;
            temp1=temp1->next;
            
        }
        cout<<c<<" ";
        if(temp1==NULL && c>0) {
            ListNode* x = new ListNode(c);
            p->next = x;
            x->next = NULL;
        }
        return l1;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0,n2=0;
        
        auto temp1 = l1;
        auto temp2 = l2;
        
        while(temp1) {
            n1++;
            temp1=temp1->next;
        }
        while(temp2) {
            n2++;
            temp2=temp2->next;
        }
        
        if(n1>=n2) {
            return func(l1,l2);
        }
        else {
            return func(l2,l1);
        }
        // return l1;
    }
};