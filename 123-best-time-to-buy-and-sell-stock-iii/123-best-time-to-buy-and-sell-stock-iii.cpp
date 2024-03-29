class Solution {
public:
    vector<vector<int>>dp;
    
    int maxProfit(vector<int>& a) {
        int n = a.size();
        dp.resize(n+1,vector<int>(5,0));
        for(int i=n-1;i>=0;i--) {
            for(int j=3;j>=0;j--) {
                if(j%2==0) {
                    dp[i][j] = max(-a[i]+dp[i+1][j+1],dp[i+1][j]);
                }
                else dp[i][j] = max(a[i]+dp[i+1][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};