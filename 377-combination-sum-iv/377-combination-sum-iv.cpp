class Solution {
public:
    vector<int>dp;
    int func(vector<int>&a, int sum) {
        if(sum==0) {
            return 1;
        }
        if(sum<0) return 0;
        if(dp[sum]!=-1) return dp[sum];
        int ans = 0;
        for(int j=0;j<a.size();j++) {
            ans+=func(a,sum-a[j]);
        }
        return dp[sum] = ans;
    }
    int combinationSum4(vector<int>& a, int sum) {
        int n = a.size();
        dp.resize(sum+1,-1);
        return func(a,sum);
    }
};