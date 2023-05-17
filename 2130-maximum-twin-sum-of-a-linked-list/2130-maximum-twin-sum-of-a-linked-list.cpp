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
    int pairSum(ListNode* head) {
        vector<int>v;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;
        while(fast && fast->next) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* a = head;
        while(1) {
            v.push_back(a->val);
            if(a == temp) break;
            a=a->next;
        }
        reverse(v.begin(),v.end());
        a=a->next;
        int maxi = 0;
        int i = 0;
        while(a) {
            maxi = max(maxi, v[i] + a->val);
            i++;
            a=a->next;
        }
        
        return maxi;
    }
};