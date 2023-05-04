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
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        int n1 = 0;
        int n2 = 0;
        ListNode* h1 = head1;
        while(h1) {
            h1=h1->next;
            n1++;
        }
        ListNode* h2 = head2;
        while(h2) {
            h2=h2->next;
            n2++;
        }
        int k;
        if(n1>n2){
            h1 = head1;
            h2 = head2;
            k = n1-n2;
        }
        else {
            h1 = head2;
            h2 = head1;
            k = n2-n1;
        }
        
        cout<<k<<endl;
        while(k--) {
            h1=h1->next;
        }
        while(h1!=h2) {
            h1=h1->next;
            h2=h2->next;
        }
        return h1;
    }
};