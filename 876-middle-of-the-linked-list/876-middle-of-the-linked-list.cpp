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
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        auto temp = head;
        while(temp!=NULL) {temp=temp->next; n++;}
        
        if(n%2==0) {
            auto x = head;
            int p = n/2;
            while(p--) {
                x=x->next;
            }
            return x;
        }
        else {
            auto x = head;
            int p = n/2 ;
            while(p--) {
                x = x->next;
            }
            return x;
        }
        return NULL;
    }
};