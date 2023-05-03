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
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* last = NULL;
        ListNode* prev = NULL;
        int c = 0;
        while(h1 || h2) {
            int sum = 0;
            if(h1) sum+=h1->val;
            if(h2) sum+=h2->val;
            sum+=c;
            c = sum/10;
            sum = sum%10;
            cout<<sum<<" ";
            if(h1) {h1->val = sum; last = h1; prev = l1;}
            if(h2) {h2->val = sum; last = h2; prev = l2;}
            if(h1) h1=h1->next;
            if(h2) h2=h2->next;
        }
        cout<<c<<endl;
        if(c!=0) {
            ListNode* carry = new ListNode(c);
            last->next = carry;
        }
        //cout<<endl;
        if(prev==l1) {
                return l1;
            }    
            else {
                return l2;
            }
    }
};