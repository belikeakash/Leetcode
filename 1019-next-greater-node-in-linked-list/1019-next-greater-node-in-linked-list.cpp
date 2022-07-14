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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<ListNode*>s;
        ListNode* temp = head;
        vector<int>ans;
        map<ListNode*,int>m;
        s.push(temp);
        temp = temp->next;
        while(temp) {
            if(s.empty()) {
                s.push(temp);
                continue;
            }
            while(s.empty()==false && s.top()->val<temp->val) {
                m[s.top()] = temp->val;
                // ans.push_back(temp->val);
                s.pop();
            }
            s.push(temp);
            temp=temp->next;
        }
        while(!s.empty()) {
            m[s.top()] = 0;
            // ans.push_back(0);
            s.pop();
        }
        temp = head;
        while(temp) {
            ans.push_back(m[temp]);
            temp = temp->next;
        }
        return ans;
    }
};