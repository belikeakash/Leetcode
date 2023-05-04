/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int>m;
        ListNode* temp = head;
        while(temp) {
            if(m[temp]>1) return temp;
            m[temp]++;
            temp=temp->next;
        }
        return NULL;
    }
};