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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* x = new ListNode(-1);
        ListNode* xhead = x;
        ListNode* h1 = list1;
        ListNode* h2 = list2;
        while(h1 && h2) {
            if(h1->val<=h2->val) {
                x->next = h1;
                h1=h1->next;
                x=x->next;
                x->next = NULL;
            }
            else {
                x->next = h2;
                h2=h2->next;
                x=x->next;
                x->next = NULL;
            }
        }
        while(h1) {
            x->next = h1;
            h1=h1->next;
            x=x->next;
            x->next = NULL;
        }
        while(h2) {
            x->next = h2;
            h2=h2->next;
            x=x->next;
            x->next = NULL;
        }
        
        return xhead->next;
    }
};