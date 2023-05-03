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
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* a = head;
        ListNode* b = head->next;
        while(a && b) {
            a->next = b->next;
            b->next = head;
            head = b;
            b = a->next;
        }
        
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);
        if(n==1) {
            head = head->next;
        }
        else {
            ListNode* a = head;
            ListNode* b = head->next;
            while(n>2) {
                a=a->next;
                b=b->next;
                n--;
            }
            a->next = b->next;
        }
       return reverse(head);
    }
};
