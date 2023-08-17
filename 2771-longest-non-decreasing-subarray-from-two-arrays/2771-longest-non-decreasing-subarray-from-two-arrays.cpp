class Solution {
public:
    vector<vector<int>>dp;
    int func(int prev, int i, vector<int>&a, vector<int>&b) {
        if(i==a.size()) return 0;
        int u = 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        if(prev==-1) {
            u = max(u, 1+func(0, i+1, a, b));
            u = max(u, 1+func(1, i+1, a, b));
            u = max(u, func(-1, i+1, a ,b));
        }
        else {
            int prevId = 0;
            if(prev==0) prevId = a[i-1];
            else prevId = b[i-1];
            if(a[i]>=prevId) u = max(u, 1+func(0, i+1, a, b));
            if(b[i]>=prevId) u = max(u, 1+func(1, i+1, a, b));
        }
        
        return dp[i][prev+1] = u;
    }
    int maxNonDecreasingLength(vector<int>& a, vector<int>& b) {
        int n = a.size();
        dp.resize(n+1, vector<int>(3,-1));
        return func(-1, 0, a, b);
    }
};