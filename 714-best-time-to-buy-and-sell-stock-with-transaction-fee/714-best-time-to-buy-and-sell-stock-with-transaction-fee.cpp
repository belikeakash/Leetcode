class Solution {
public:
    vector<vector<int>>dp;
    int func(int i, int t, vector<int>&a, int x) {
        if(i>=a.size()) return 0;
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
    int maxProfit(vector<int>& a, int x) {
        int n = a.size();
        dp.resize(a.size()+1,vector<int>(2,0));
        // return func(0,0,a,fee);
        for(int i=n-1;i>=0;i--) {
            for(int j=1;j>=0;j--) {
                if(j==0) {
                    dp[i][j] = max(-a[i] + dp[i+1][1], dp[i+1][0]);
                }
                else {
                    dp[i][j] = max(a[i]+dp[i+1][0]-x,dp[i+1][1]);
                }
            }        
        }
        return dp[0][0];
    }
};