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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        while(head!=NULL && head->val==val) {
            head=head->next;
        }
        if(head==NULL) return head;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        while(temp2) {
            if(temp2->val==val) temp2 = temp2->next;
            else {
                temp1->next = temp2;
                temp1 = temp2;
                temp2=temp2->next;
            }
        }    
        temp1->next = temp2;
        return head;
    }
};