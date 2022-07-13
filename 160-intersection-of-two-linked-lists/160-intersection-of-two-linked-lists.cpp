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
        int n1=0,n2=0;
        while(temp!=NULL) {
            // m[temp] = temp->next;
            temp = temp->next;
            n1++;
        }
        temp = h2;
        while(temp!=NULL) {
            // if(m.count(temp)) {
            //     return temp;
            // }
            temp = temp->next;
            n2++;
        }
        int t = abs(n1-n2);
        if(n1>n2){
            
            while(t--) {
                h1=h1->next;
            }
        }
        else {
            while(t--) {
                h2=h2->next;
            }
        }
        while(h1!=NULL && h2!=NULL) {
            if(h1==h2) return h1;
            h1=h1->next;
            h2=h2->next;
        }
        return NULL;
    }
};