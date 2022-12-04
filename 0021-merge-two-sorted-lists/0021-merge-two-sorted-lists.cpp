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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(list1 && list2) {
            if(list1->val<list2->val) {
                ListNode* c = new ListNode(list1->val);
                dummy->next = c;
                list1=list1->next;
                dummy = dummy->next;
            }
            else {
                ListNode* c = new ListNode(list2->val);
                dummy->next = c;
                list2=list2->next;
                dummy = dummy->next;
            }
        }
        while(list1) {
            ListNode* c = new ListNode(list1->val);
                dummy->next = c;
                list1=list1->next;
                dummy = dummy->next;
        }
        while(list2) {
            ListNode* c = new ListNode(list2->val);
                dummy->next = c;
                list2=list2->next;
                dummy = dummy->next;
        }
        
        return temp->next;
    }
};