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
        if(k==0) return head;
        if(!head || !head->next) return head;
        ListNode* a = head;
        int len = 0;
        while(a) {
            a=a->next;
            len++;
        }
        a = head;
        k = k%len;
        if(k==0) return head;
        int n = k-1;
        while(n--) {
            if(!a->next) a = head;
            else a = a->next;
        }
        ListNode* temp = NULL;
        ListNode* b = head;
        while(a->next!=NULL) {
            temp = b;
            b=b->next;
            a=a->next;
        }
        if(temp==NULL) {
            return head;
        }
        cout<<temp->val<<" ";
        ListNode* x = temp->next;
        ListNode* u = x;
        temp->next = NULL;
        while(x->next!=NULL) {
            x=x->next;
        }
        x->next = head;
        head = u;
        return head;
    }
};