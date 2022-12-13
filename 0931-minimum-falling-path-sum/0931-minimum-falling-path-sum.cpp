class Solution {
public:
    vector<vector<int>>dp;
    int func(int i, int j, vector<vector<int>>&a) {
        int n = a.size();
        if(i==n) return 0;
        if(j<0 || j>=n) return 1e6;
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        return dp[i][j] = a[i][j] + min({func(i+1,j,a), func(i+1,j-1,a), func(i+1,j+1,a)});
    }
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        dp.resize(n+2,vector<int>(n+2,INT_MIN));
        int ans = INT_MAX;
        for(int i=0;i<n;i++) {
            ans=min(ans,func(0,i,a));
        }
        
        return ans;
    }
};