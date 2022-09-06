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
    ListNode* rotateRight(ListNode* head, int k) {
        // int k = 
        if(head==NULL || k==0) return head;
        int n = 0;
        ListNode* v = head;
        while(v) {
            n++;
            v=v->next;
        }
        k = k%n;
        cout<<k<<" ";
        if(k==0) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i=0;i<k;i++) {
            fast = fast->next;
        }
        // cout<<fast->val<<endl;
        while(fast->next!=NULL) {
            // cout<<slow->val<<" ";
            slow = slow->next;
            fast = fast->next;
        }
        // cout<<slow->val<<endl;
        ListNode* temp = head;
        temp = slow->next;
        slow->next = NULL;
        ListNode* temp2 = temp;
        while(temp2->next!=NULL) {
            temp2=temp2->next;
        }
        temp2->next = head;
        return temp;
    }
};