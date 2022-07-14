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
    int numComponents(ListNode* head, vector<int>& a) {
        unordered_map<int,int>m;
        for(auto x:a) {
            m[x]=1;
        }
        int ans = 0;
        int cc = 0;
        while(head) {
            int x = head->val;
            if(m[x]) {
                cc++;
            }
            else {
                if(cc>0) ans++;
                cc=0;
            }
            
            head=head->next;
        }
        if(cc>0)ans++;
        return ans;
    }
};