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
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        map<ListNode*,ListNode*>m;
        ListNode* temp = h1;
        while(temp!=NULL) {
            m[temp] = temp->next;
            temp = temp->next;
        }
        temp = h2;
        while(temp!=NULL) {
            if(m.count(temp)) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};