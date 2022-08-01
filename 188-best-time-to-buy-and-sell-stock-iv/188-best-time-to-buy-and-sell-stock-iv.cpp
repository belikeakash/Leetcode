class Solution {
public:
    int func(int i, int t, vector<int>&a, vector<vector<int>>&dp) {
        if(i==a.size() || t==0) return 0;
        if(dp[i][t]!=-1)return dp[i][t];
        if(t%2==0) {
            int p1 = -a[i] + func(i+1,t-1,a,dp);
            int p2 = func(i+1,t,a,dp);
            return dp[i][t] = max(p1,p2);
        }
        else {
            int p3 = a[i] + func(i+1,t-1,a,dp);
            int p4 = func(i+1,t,a,dp);
            return dp[i][t] = max(p3,p4);
        }
    }
    int maxProfit(int k, vector<int>& a) {
        vector<vector<int>>dp(a.size()+1,vector<int>(2*k +2,-1));
        int ans = func(0,2*k,a,dp);
        return ans;
    }
};