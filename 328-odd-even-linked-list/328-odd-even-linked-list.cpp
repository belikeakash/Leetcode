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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        auto t1 = head;
        auto t2 = head->next;
        ListNode* t3 = NULL;
        auto p = t2;
        int n = 1;
        while(t1->next) {
            n++;
            t3 = t1;
            t1->next = t1->next->next;
            t1 = t2;
            t2 = t1->next;
        }
        cout<<n<<endl;
        cout<<p->val<<" "<<t3->val<<endl;
        if(n%2==0) t3->next = p;
        else t1->next = p;
        return head;
    }
};