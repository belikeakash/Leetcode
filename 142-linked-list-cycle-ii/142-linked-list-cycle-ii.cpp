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
    bool findCycle(ListNode* head) {
        if(head==NULL) return 0;
        ListNode* slow = head;
        ListNode* fast = head;
        int c = 100009;
        while(c--) {
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
                if(slow==fast) return 1;
            }
        }
        return 0;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;
        int ans = findCycle(head);
        if(ans == 0) return NULL;
        unordered_map<ListNode*,int>m;
        ListNode* temp = head;
        int c = 0;
        // cout<<c<<endl;
        while(temp) {
            cout<<"-";
            if(m[temp]) {cout<<temp->val<<endl; return temp;}
            m[temp]=1;
            c++;
            temp=temp->next;
        }
        cout<<"a";
        cout<<endl;
        return head;
    }
};