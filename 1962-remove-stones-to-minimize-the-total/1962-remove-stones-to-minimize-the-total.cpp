class Solution {
public:
    int minStoneSum(vector<int>& a, int k) {
        priority_queue<int>q;
        for(auto x:a) {
            q.push(x);
        }
        while(k--) {
            int c = q.top();
            q.pop();
            int u = c - c/2;
            q.push(u);
        }
        int ans = 0;
        while(!q.empty()) {
            //cout<<q.top()<<" ";
            ans+=q.top();
            q.pop();
        }
        return ans;
    }
};