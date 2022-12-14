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
    ListNode* reverseList(ListNode* head2) {
        if(!head2 || !head2->next) return head2;
        ListNode* dummy = new ListNode(0);
        dummy->next = head2;
        ListNode* h = dummy;
        ListNode* p1 = head2;
        ListNode* p2 = head2->next;
        ListNode* xp = head2;
        head2 = dummy;
        while(1) {
            p1->next = head2;
            h->next = p2;
            head2 = p1;
            p1=p2;
            if(p1==NULL) break;
            p2=p2->next;
            
            
        }
        // ListNode* head1 = head2;
        xp->next = NULL;
        // while(head1) {
        //     cout<<head1->val<<" ";
        //     head1=head1->next;
        // }
        
        return head2;
    }
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast&&fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* nn = slow->next;
        // if(!nn) return head;
        ListNode* revs = reverseList(nn);
        ListNode* t1 = head;
        ListNode* t2 = head->next;
        slow->next = NULL;
        // while(revs) {
        //     cout<<revs->val<<" ";
        //     revs=revs->next;
        // }
        // cout<<endl;
        // while(head) {
        //     cout<<head->val<<" ";
        //     head=head->next;
        // }
        // cout<<endl;
        ListNode* px = t1;
        while(revs) {
            cout<<revs->val<<" ";
            ListNode* temp = revs->next;
            t1->next = revs;
            revs->next = t2;
            t1 = t2;
            t2=t2->next;
            revs=temp;
        }
        head = px;
        
    }
};