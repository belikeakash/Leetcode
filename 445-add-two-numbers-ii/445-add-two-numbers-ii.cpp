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
        // cout<<"a";
        int x = 0,c=0;
        ListNode* pre = NULL;
        ListNode* a = l1;
        ListNode* b=l2;
        while(a!=NULL) {
            x = 0;
            pre = a;
            if(b!=NULL) x=b->val ;
            x+=a->val + c;
            c = x/10;
            a->val = x%10;
            // cout<<x<<" ";
            a=a->next;
            if(b!=NULL)b=b->next;
        }
        cout<<c<<endl;
        if(c>0) {
            ListNode* temp = new ListNode(c);
            pre->next = temp;
        }
        auto temp = l1;
        while(temp) {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        return l1;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0,n2=0;
        ListNode* temp = l1;
        while(temp) {
            n1++;
            temp=temp->next;
        }
        temp = l2;
        while(temp) {
            n2++;
            temp=temp->next;
        }
        ListNode* a = l1;
        ListNode* b = l1->next;
        while(b) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        l1->next = NULL;
        l1 = a;
        
        a = l2;
        b = l2->next;
        while(b) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        l2->next = NULL;
        l2 = a;
        ListNode* ans;
        if(n1>n2) {
            ans = func(l1,l2);
        }
        else {
            ans = func(l2,l1);
        }
        cout<<ans->val<<" ";
        a = ans;
        b = ans->next;
        while(b) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        ans->next = NULL;
        ans = a;
        return ans;
    }
};