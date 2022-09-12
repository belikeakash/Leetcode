class Solution {
public:
    vector<vector<int>>dp;
    int func(int x, int y) {
        if(x>=y) {
            return 0;
        }
        if(dp[x][y]!=-1) return dp[x][y];
        int ans = INT_MAX;
        for(int i=x;i<=y;i++) {
            ans =  min(ans,max(i+func(x,i-1),i+func(i+1,y)));
        }
        return dp[x][y] = ans;
    }
    int getMoneyAmount(int n) {
        dp.resize(n+1,vector<int>(n+1,-1));
        return func(1,n);
    }
};