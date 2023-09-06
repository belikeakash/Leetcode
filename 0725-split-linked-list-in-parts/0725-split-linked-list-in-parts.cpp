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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp=temp->next;
        }
        ListNode* dummy = new ListNode(-1);
        dummy = head;
        int req = len/k;
        int ext = len - k*req;
        while(k--) {
            int c = req;
            if(ext>0) c++;
            //cout<<c<<" ";
            ext--;
            ListNode* a = dummy;
            ListNode* b = a;
            c--;
            //cout<<endl;
            while(c>0) {
                //cout<<b->val<<" ";
                b = b->next;
                c--;
            }
            if(dummy!=NULL) {dummy = b->next;
            b->next = NULL;}
            ans.push_back(a);
        }
        cout<<endl;
        return ans;
    }
};