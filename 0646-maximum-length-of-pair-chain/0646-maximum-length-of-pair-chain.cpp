class Solution {
    vector<vector<int>>dp;
public:
    int helper(vector<vector<int>>&a, int idx) {
        int ans = INT_MAX;
        
        int l = idx+1, r = a.size()-1;
        int x = a[idx][1];
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(a[mid][0]>x) {
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        
        return ans;
    }
    int func(int prev, int i, vector<vector<int>>&a) {
        if(i>=a.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int idx = helper(a, i);
        if(prev==-1) {
            return dp[i][prev+1] = max(1+func(i, idx, a), func(-1, i+1, a));
        }
        return dp[i][prev+1] = max( 1 + func(i, idx, a), func(prev, i+1, a));
    }
    int findLongestChain(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return func(-1, 0, a);
    }
};