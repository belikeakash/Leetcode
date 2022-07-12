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
    ListNode* solve(ListNode* h1, ListNode* h2) {
        ListNode* curr1 = h1;
        ListNode* next1 = curr1->next;
        ListNode* curr2 = h2;
        ListNode* next2 = curr2->next;
        if(next1==NULL) {
            curr1->next = curr2;
            return h1;
        }
        
        while(next1!=NULL && curr2!=NULL) {
            cout<<next1->val<<" ";
            if(curr2->val >= curr1->val && curr2->val <=next1->val) {
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next = next1;
                curr1 = curr2;
                curr2 = next2;
            }
            else {
                curr1 = next1;
                next1 = next1->next;
                if(next1==NULL) {
                    curr1->next = curr2;
                    return h1;
                }
            }
        }
        return h1;
    }
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if(h1==NULL) return h2;
        if(h2==NULL) return h1;
        if(h1->val<=h2->val) {
            return solve(h1,h2);
        }
        else {
            return solve(h2,h1);
        }
    }
};