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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* dumm = dummy;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1!=NULL && temp2!=NULL) {
            if(temp1->val < temp2->val) {
                dumm->next = new ListNode(temp1->val);
                dumm=dumm->next;
                temp1=temp1->next;
            }
            else {
                dumm->next = new ListNode(temp2->val);
                dumm=dumm->next;
                temp2=temp2->next;
            }
        }
        while(temp1) {
            dumm->next = new ListNode(temp1->val);
            dumm=dumm->next;
            temp1=temp1->next;
        }
        while(temp2) {
            dumm->next = new ListNode(temp2->val);
            dumm=dumm->next;
            temp2=temp2->next;
        }
        return dummy->next;
    }
};