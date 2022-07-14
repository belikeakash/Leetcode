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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        ListNode* pre = NULL;
        if(!temp2) return temp1;
        int flag = 1;
        int x = 5002;
        while(x--) {
        temp1 = head;
        temp2 = head->next;
        pre = NULL;
            while(temp2) {
                // cout<<temp2->val<<" "<<temp1->val<<" "<<head->val<<endl;
                if(temp1->val > temp2->val ) {
                if(temp1 == head) {
                    temp1->next = temp2->next;
                    temp2->next = temp1;
                    head = temp2;
                }
                else {
                   temp1->next = temp2->next;
                    temp2->next = temp1;
                    pre->next = temp2;
                }
                auto x = temp1;
                temp1 = temp2;
                temp2 = x;
                // auto u = head;
                // while(u) {
                //     cout<<u->val<<" ";
                //     u=u->next;
                // }
                // cout<<endl;
            }
            pre = temp1;
            temp1=temp1->next;
            temp2=temp2->next;
            
            
            }
            
        }
        return head;
    }
};