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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(n==m) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;
        ListNode* prev = NULL;
        for(int i=0;i<m;i++) {
            prev = temp;
            temp=temp->next;
        }
        ListNode* tmp = dummy;
        for(int i=0;i<n;i++) {
            tmp = tmp->next;
        }
        tmp=tmp->next;
        // cout<<tmp->val<<" ";
        ListNode* a = temp;
        ListNode* b = temp->next;
        ListNode* f = temp;
        // cout<<a->val<<" "<<b->val<<endl;
        for(int i=0;i<n-m;i++) {
            ListNode* c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        prev->next = a;
        f->next = tmp;
        return dummy->next;
    }
};