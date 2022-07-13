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
    vector<ListNode*> splitListToParts(ListNode* head, int x) {
        vector<ListNode*>a(x, NULL);
        int i = 0;
        int n = 0;
        ListNode* temp = head;
        while(temp) {
            temp = temp->next;
            n++;
        }
        // cout<<n<<endl;
        while(head) {
            // if(i==x) i=0;
            int k = (n-1)/x-- + 1;
            n = n-k;
            ListNode* f;
            cout<<k<<" "<<i<<endl;
            while(k--){
                if(head==NULL) break;
                ListNode* temp = new ListNode(head->val);
                // cout<<temp->val<<" "<<i<<endl;
                if(a[i]==NULL) {a[i]=temp; f = a[i];}
                else {f->next = temp; f = f->next;}
                head=head->next;
            }
            i++;
            cout<<i<<endl;
        }
        return a;
    }
};