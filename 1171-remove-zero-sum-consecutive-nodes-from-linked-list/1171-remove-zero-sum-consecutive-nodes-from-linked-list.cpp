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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp = new ListNode(0);
        ListNode* i = temp;
        i->next = head;
        while(i!=NULL) {
            int sum = 0;
            ListNode* j = i->next;
            while(j!=NULL) {
                sum+=j->val;
                if(sum==0) {
                    i->next = j->next;
                }
                j=j->next;
            }
            i=i->next;
        }
        return temp->next;
    }
};