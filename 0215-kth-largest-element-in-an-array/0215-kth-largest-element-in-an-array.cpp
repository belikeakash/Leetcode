class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        priority_queue<int>q;
        for(auto x:a) {
            q.push(x);
        }
        k--;
        while(k--) {
            q.pop();
        }
        return q.top();
    }
};