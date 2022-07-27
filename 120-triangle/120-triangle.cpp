class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[n-1].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=a[i].size()-1;j>=0;j--) {
                dp[i][j] = a[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[0][0];
    }
};