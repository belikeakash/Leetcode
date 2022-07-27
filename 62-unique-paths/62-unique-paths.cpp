class Solution {
public:
    vector<vector<int>>dp;
    int func(int i, int j, int m, int n) {
        if(i==m || j==n) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = func(i+1,j,m,n) + func(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        dp.resize(m+1,vector<int>(n+1,-1));
        return func(1,1,m,n);
    }
};