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
        string s = "";
        while(head) {
            s+=head->val;
            head=head->next;
        }
        for(int i=0;i<s.size();i++) {
            if(s[i]!=s[s.size()-1-i]) return 0;
        }
        return 1;
    }
};