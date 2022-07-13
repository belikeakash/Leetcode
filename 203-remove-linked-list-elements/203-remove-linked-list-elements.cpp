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
    ListNode* removeElements(ListNode* head, int x) {
        if(head==NULL) return head;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!=NULL) {
            if(head==NULL) return head;
            if(head->val==x) {
                ListNode* temp = head;
                head = head->next;
                temp->next = NULL;
                curr = head;
                prev = NULL;
            }
            else {
                if(curr->val==x) {
                    ListNode* temp = curr;
                    prev->next = curr->next;
                    curr=curr->next;
                    temp->next = NULL;
                }
                else {
                    prev=curr;
                curr=curr->next;
                }
                
            }
        }
        return head;
    }
};