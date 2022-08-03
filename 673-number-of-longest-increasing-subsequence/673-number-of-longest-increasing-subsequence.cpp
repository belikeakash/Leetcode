class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        int maxi = 1;
        vector<int>dp(n,1);
        vector<int>ans(n,1);
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(a[i]>a[j] && dp[i]<dp[j]+1) {
                    dp[i] = dp[j] + 1;
                    ans[i]=ans[j];
                }
                else if(a[i]>a[j] && dp[i]==dp[j]+1) {
                    ans[i]+=ans[j];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(dp[i]==maxi) cnt+=ans[i];
        }
        return cnt; 
    }
};