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
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* a = head;
        ListNode* b = head->next;
        while(a && b) {
            a->next = b->next;
            b->next = head;
            head = b;
            b = a->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int n) {
        if(n==1) return head;
        if(!head->next)  return head;
        ListNode* temp = head;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head;
        ListNode* prv = NULL;
        while(1) {
            int k = n-1;
            temp = c;
            //cout<<"temp-> "<<temp->val<<" ";
            while(k-- && temp) {
                temp = temp->next;
            }
            if(!temp) break;
            //cout<<"temp-> "<<temp->val<<" ";
            
            ListNode* nxt = temp->next;
             //cout<<"nxt-> "<<nxt->val<<" ";
            temp->next = NULL;
            ListNode* a = c;
            ListNode* b = c->next;
            while(a && b) {
                a->next = b->next;
                b->next = c;
                c = b;
                b = a->next;
            }
            ListNode* ll = c;
            ListNode* u = ll;
            //cout<<"ll-> "<<ll->val<<" ";
            // while(u) {
            //     cout<<u->val<<" ";
            //     u=u->next;
            // }
            //cout<<"a-> "<<a->val<<" ";
            //cout<<"c-> "<<c->val<<" ";
            // if(prv!=NULL) cout<<"prv-> "<<prv->val<<" ";
            if(prv!=NULL) {
                prv->next = c;
            }
            else if(prv==NULL) {
                head = ll;
            }
            a->next = nxt;
            prv = a;
            a = nxt;
            
            if(a) b = nxt->next;
            if(!a) break;
            c = a;
            ListNode* cc = head;
            // cout<<"xxxx ";
            // while(cc) {
            //     cout<<cc->val<<" ";
            //     cc=cc->next;
            // }
            // cout<<endl;
        }
        return head;
    }
};