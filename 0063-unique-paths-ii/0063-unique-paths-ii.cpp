class Solution {
public:
    int ans = 0;
    vector<vector<int>>dp;
    int func(int i, int j, vector<vector<int>>&a, int n, int m) {
        if(i>=n || i<0 || j>=m || j<0 || a[i][j]==1) return 0;
        cout<<i<<" "<<j<<endl;
        if(i==n-1 && j==m-1) {return 1;}
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        
        ans+=func(i+1, j, a, n, m);
        ans+=func(i, j+1, a, n, m);
        
        return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        dp.resize(n+1, vector<int>(m+1, -1));
        return func(0,0,a,n,m);
    }
};