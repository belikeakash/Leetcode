class Solution {
public:
    vector<vector<int>>dp;
    // int func(int i, int t, vector<int>&a) {
    //     if(i>=a.size() || t>=a.size()) return 0;
    //     if(dp[i][t]!=-1) return dp[i][t];
    //     if(t==0) {
    //         int p1 = -a[i] + func(i+1,1,a);
    //         int p2 = func(i+1,t,a);
    //         return dp[i][t] = max(p1,p2);
    //     }
    //     else {
    //         int p3 = a[i] + func(i+2,0,a);
    //         int p4 = func(i+1,t,a);
    //         return dp[i][t] = max(p3,p4);
    //     }
    // }
    int maxProfit(vector<int>& a) {
        int n = a.size();
        dp.resize(n+2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--) {
            for(int j=1;j>=0;j--) {
                if(j==0) {
                    dp[i][j] = max((-a[i]+dp[i+1][1]), dp[i+1][0]);
                }
                else {
                    dp[i][j] = max((a[i]+dp[i+2][0]),dp[i+1][1]);
                }
            }
        }
        return dp[0][0];
    }
};