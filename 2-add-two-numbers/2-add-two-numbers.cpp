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
        int c = 0;
        auto t1 = l1;
        auto t2 = l2;
        ListNode* t3 = new ListNode(0); 
        auto p = t3;
        while(c || l1 || l2) {
            int x = c + (l1?l1->val : 0) + (l2?l2->val : 0);
            c = x/10;
            x = x%10;
            
            t3->next = new ListNode(x);
            t3 = t3->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return p->next;
    }
};