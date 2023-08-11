class Solution {
public:
    vector<vector<int>>dp;
    int func(int i, int sum, vector<int>&a) {
        if(sum==0) {
        return 1;}
        if(i>=a.size()) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int ans = 0;    
        if(a[i]<=sum) {
            ans= func(i, sum-a[i], a) ;
        }
        ans+=func(i+1, sum, a);
        return dp[i][sum] = ans;
    }
    int change(int x, vector<int>& a) {
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        dp.resize(a.size()+1, vector<int>(x+1, -1));
        return func(0, x, a);
    }
};