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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        ListNode* temp;
        stack<int>s;
        while(fast && fast->next) {
            fast = fast->next->next;
            s.push(slow->val);
            slow = slow->next;
        }
        if(fast) slow = slow->next;
        while(!s.empty()) {
            if(s.top()!=slow->val) return 0;
            s.pop();
            slow=slow->next;
        }
        cout<<endl;
        return 1;
        
     
    }
};