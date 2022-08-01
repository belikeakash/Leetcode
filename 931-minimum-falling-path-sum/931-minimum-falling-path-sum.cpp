class Solution {
public:
    vector<vector<int>>dp;
//     int func(int i, int j, int n, int m, vector<vector<int>>& a) {
//         if(i==n) return 0;
//         if(dp[i][j]!=INT_MIN) return dp[i][j];
//         int a1=INT_MAX,a2=INT_MAX,a3=INT_MAX;
//         if(j+1<m) a1 = a[i][j] + func(i+1,j+1,n,m,a);
//         if(j-1>=0) a2 = a[i][j] + func(i+1,j-1,n,m,a);
//         a3 = a[i][j] + func(i+1,j,n,m,a);
        
//         return dp[i][j] = min({a1,a2,a3});
//     }
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        dp.resize(n,vector<int>(m,0));
        int ans = INT_MAX;
        for(int i=0;i<m;i++) {
            dp[0][i] = a[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++) {
                if(j==0) dp[i][j] = a[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
                else if(j==m-1) dp[i][j] = a[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                else dp[i][j] = a[i][j] + min({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]});
            }
        }
        for(int i=0;i<m;i++) {
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};