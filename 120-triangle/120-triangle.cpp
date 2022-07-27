class Solution {
public:
    int func(int i, int j, int n, int m, vector<vector<int>>& a, vector<vector<int>>& dp) {
        if(i==n) return 0;
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        return dp[i][j] =  a[i][j] + min(func(i+1,j,n,m,a,dp), func(i+1,j+1,n,m,a,dp));
    }
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[n-1].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MIN));
        return func(0,0,n,m,a,dp);
    }
};