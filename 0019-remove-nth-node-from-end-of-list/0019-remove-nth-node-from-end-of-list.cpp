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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp = dummy;
        ListNode* p1 = head;
        ListNode* p2 = dummy;
        int k = n;
        while(k--) {
            p2 = p2->next;
        }
        while(p2->next!=NULL) {
            p1=p1->next;
            p2=p2->next;
            temp=temp->next;
        }
        temp->next = p1->next;
        
        return dummy->next;
    }
};
