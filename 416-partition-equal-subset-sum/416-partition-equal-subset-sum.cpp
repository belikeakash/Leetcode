class Solution {
public:
    vector<vector<int>>dp;
    bool func(int i, vector<int>&a,int x, int sum) {
        if(i>=a.size()) return 0;
        if(x==sum) return 1;
        if(dp[x][i]!=-1) return dp[x][i];
        return dp[x][i] = func(i+1,a,x+a[i],sum) || func(i+1,a,x,sum);
    }
    bool canPartition(vector<int>& a) {
        int n = a.size();
        int sum = 0;
        for(auto x:a) sum+=x;
        if(sum%2!=0) return 0;
        dp.resize(sum,vector<int>(n,-1));
        return func(0,a,0,sum/2);
    }
};