class Solution {
public:

    int rob(vector<int>& a) {
        int n = a.size();
        vector<int>dp(n+2,0);
        for(int i=2;i<n+2;i++) {
            dp[i] = max(dp[i-1],a[i-2]+dp[i-2]);
        }
        return dp[n+1];
    }
};