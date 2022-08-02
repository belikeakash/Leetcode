class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& a) {
        vector<int>ans;
        int n = a.size();
        sort(a.begin(),a.end());
        int maxi = 1;
        int idx = 0;
        vector<int>dp(n,1);
        vector<int>hash(n);
        for(int i=1;i<n;i++) {
            hash[i]=i;
            for(int j=0;j<i;j++) {
                if(a[i]%a[j]==0 && dp[j]+1>dp[i]) {
                        dp[i] = dp[j]+1;
                        hash[i] = j;
                }
            }
            if(dp[i]>maxi) {
                maxi = dp[i];
                idx = i;
            }
        }
        ans.push_back(a[idx]);
        while(hash[idx]!=idx) {
            idx = hash[idx];
            ans.push_back(a[idx]);
        }
        return ans;
    }
};