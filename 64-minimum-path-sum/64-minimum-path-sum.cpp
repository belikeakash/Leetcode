class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(i==1) dp[i][j] = dp[i][j-1] + a[i-1][j-1];
                else if(j==1) dp[i][j] = dp[i-1][j] + a[i-1][j-1];
                else dp[i][j] = a[i-1][j-1] + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};