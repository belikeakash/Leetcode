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
        unordered_map<int,ListNode*>m;
        ListNode* temp = head;
        ListNode* newhead = head;
        int sum = 0;
        bool flag = 0;
        while(temp!=NULL) {
            sum+=temp->val;
            if(sum==0) {
                newhead = temp->next;
                flag = 1;
            }
            else if(m[sum]) {
                m[sum]->next = temp->next;
                flag = 1;
            }
            else {
                m[sum] = temp;
            }
            temp=temp->next;
        }
        if(flag) removeZeroSumSublists(newhead);
        return newhead;
    }
};