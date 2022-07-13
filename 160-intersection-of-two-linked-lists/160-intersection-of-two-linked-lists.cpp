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
        ListNode* a = h1;
        ListNode* b = h2;
        while(a!=b) {
            if(a==NULL) {
                a = h2;
            }
            else {
                a = a->next;
            }
            if(b==NULL) {
                b = h1;
            }
            else {
                b = b->next;
            }
        }
        return a;
    }
};