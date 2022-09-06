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
    ListNode* removeNthFromEnd(ListNode* head, int x) {
        int n = 0;
        ListNode* temp = head;
        while(temp) {
            temp=temp->next;
            n++;
        }
        if(x==n) return head->next;
        int z = n-x-1;
        temp=head;
        while(z--) {
            temp=temp->next;
        }
        
        temp->next = temp->next->next;
        return head;
    }
};