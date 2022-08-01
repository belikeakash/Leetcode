class Solution {
public:
    vector<vector<int>>dp;
    int func(int i, int t, vector<int>&a) {
        if(i>=a.size() || t>=a.size()) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        if(t%2==0) {
            int p1 = -a[i] + func(i+1,t+1,a);
            int p2 = func(i+1,t,a);
            return dp[i][t] = max(p1,p2);
        }
        else {
            int p3 = a[i] + func(i+2,t+1,a);
            int p4 = func(i+1,t,a);
            return dp[i][t] = max(p3,p4);
        }
    }
    int maxProfit(vector<int>& a) {
        int n = a.size();
        dp.resize(n,vector<int>(n,-1));
        return func(0,0,a);
    }
};