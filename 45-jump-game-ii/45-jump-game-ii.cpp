class Solution {
public:
    vector<int>dp;
    int func(int x, vector<int>&a) {
        // cout<<x<<" ";
        if(x>=a.size()-1) return 0;
        if(dp[x]!=-1) return dp[x];
        int ans = 100007;
        for(int i=x+1;i<=x+a[x];i++) {
            // if(i>=a.size()-1) return 0;
            ans = min(ans,1+func(i,a));
        }
        return dp[x] = ans;
    }
    int jump(vector<int>& a) {
        if(a.size()==1) return 0;
        dp.resize(a.size(),-1);
        return func(0,a);
    }
};