class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        int n = a.size();
        vector<int>dp(n,1);
        for(int i=1;i<n-1;i++) {
            for(int j=0;j<i;j++) {
                if(a[i]>a[j] && dp[i]<dp[j]+1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        vector<int>dp2(n,1);
        for(int i=n-2;i>=1;i--) {
            for(int j=n-1;j>i;j--) {
                if(a[i]>a[j] && dp2[i]<dp2[j]+1) {
                    dp2[i] = dp2[j] + 1;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            int x = dp[i]+dp2[i]-1;
            if(dp[i]>1 && dp2[i]>1) ans = max(ans,x);
        }
        return n-ans;
    }
};