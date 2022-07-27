class Solution {
public:
    vector<vector<int>>dp;
    int func(int i, int j, int n, int m, vector<vector<int>>& a) {
        if(i==n) return 0;
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int a1=INT_MAX,a2=INT_MAX,a3=INT_MAX;
        if(j+1<m) a1 = a[i][j] + func(i+1,j+1,n,m,a);
        if(j-1>=0) a2 = a[i][j] + func(i+1,j-1,n,m,a);
        a3 = a[i][j] + func(i+1,j,n,m,a);
        
        return dp[i][j] = min({a1,a2,a3});
    }
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        dp.resize(n,vector<int>(m,INT_MIN));
        int ans = INT_MAX;
        for(int i=0;i<m;i++) {
            ans = min(ans,func(0,i,n,m,a));
        }
        return ans;
    }
};