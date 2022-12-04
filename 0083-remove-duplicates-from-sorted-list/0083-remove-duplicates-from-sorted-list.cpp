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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp1 = head;
        if(temp1==NULL || temp1->next==NULL ) return head;
        ListNode* temp2 = head->next;
        while(temp2!=NULL) {
            if(temp2->val!=temp1->val) {
                temp1->next=temp2;
                temp1 = temp2;
                temp2 = temp2->next;
            }
            else {
                temp2=temp2->next;
            }
        }
        temp1->next = temp2;
        return head;
    }
};