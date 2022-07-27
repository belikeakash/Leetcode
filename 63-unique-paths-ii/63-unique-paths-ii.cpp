class Solution {
public:
    vector<vector<long long>>dp;
    // int func(int i, int j, int n, int m, vector<vector<int>>& a) {
    //     if(i>=n ||j>=m) return 0;
    //     if(i==n-1 && j==m-1) return 1;
    //     if(a[i][j]==1) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int ans = 0;
    //     if(i<n-1 && j<m-1) {
    //         ans = ans + func(i+1,j,n,m,a) + func(i,j+1,n,m,a);
    //     }
    //     else if(i==n-1) {
    //         ans = ans + func(i,j+1,n,m,a);
    //     }
    //     else {
    //         ans = ans + func(i+1,j,n,m,a);
    //     }
    //     return dp[i][j] = ans;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        if(a[n-1][m-1]==1) return 0;
        dp.resize(n+1,vector<long long>(m+1,1));
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                if(a[i][j]==1) {dp[i][j]=0;continue;}
                if(i==n-1 && j==m-1) dp[i][j] = 1;
                if(i<n-1 && j<m-1) {
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
                else if(i==n-1) {
                    dp[i][j] = dp[i][j+1];
                }
                else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][0];
        // return func(0,0,n,m,a);
    }
};