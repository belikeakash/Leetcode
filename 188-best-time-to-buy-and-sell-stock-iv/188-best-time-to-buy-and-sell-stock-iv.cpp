class Solution {
public:
    int func(int s, int k, vector<int>&a,vector<vector<int>>&dp) {
        if(s==a.size()) return 0;
        if(k==0) return 0;
        if(dp[s][k]!=-1) return dp[s][k];
        int ans1 = func(s+1,k,a,dp);
        
        bool x = (k%2==0);
        int ans2 = 0;
        if(x==true) {
            ans2 = -a[s] + func(s+1,k-1,a,dp);
        }
        else {
            ans2 = a[s] + func(s+1,k-1,a,dp);
        }
        cout<<ans1<<" "<<ans2<<endl;
        return dp[s][k] = max(ans1,ans2);
    }
    int maxProfit(int k, vector<int>& a) {
        vector<vector<int>>dp(a.size()+1,vector<int>(2*k +2,-1));
        int ans = func(0,2*k,a,dp);
        return ans;
    }
};