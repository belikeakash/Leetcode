/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        int n1 = 0;
        int n2 = 0;
        ListNode* temp = h1;
        while(temp) {
            n1++;
            temp = temp->next;
        }
        temp = h2;
        while(temp) {
            n2++;
            temp = temp->next;
        }
        if(n1>n2) {
            int c = n1-n2;
            ListNode* u1 = h1;
            ListNode* u2 = h2;
            while(c--) {
                u1 = u1->next;
            }
            while(u1!=u2) {
                u1=u1->next;
                u2=u2->next;
            }
            
            return u1;
        }
        else {
            int c = n2-n1;
            ListNode* u1 = h1;
            ListNode* u2 = h2;
            while(c--) {
                u2 = u2->next;
            }
            while(u1!=u2) {
                u1=u1->next;
                u2=u2->next;
            }
            
            return u1;
        }
    }
};