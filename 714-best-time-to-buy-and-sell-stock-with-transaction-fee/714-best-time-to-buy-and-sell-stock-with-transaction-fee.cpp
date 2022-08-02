class Solution {
public:
    vector<vector<int>>dp;
    int func(int i, int t, vector<int>&a, int x) {
        if(i>=a.size() || t>=a.size()) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        if(t==0) {
            int p1 = -a[i] + func(i+1,1,a,x);
            int p2 = func(i+1,t,a,x);
            return dp[i][t] = max(p1,p2);
        }
        else {
            int p3 = a[i] - x + func(i+1,0,a,x);
            int p4 = func(i+1,t,a,x);
            
            return dp[i][t] = max(p3,p4);
        }
    }
    int maxProfit(vector<int>& a, int fee) {
        dp.resize(a.size(),vector<int>(2,-1));
        return func(0,0,a,fee);
    }
};