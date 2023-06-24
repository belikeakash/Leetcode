class Solution {
public:
    int dp[1001][1002];
    unordered_map<int,vector<int>>mp;
    int func(int i, int prev, vector<int>&a) {
        if(i>=a.size()) return 0;
        
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int maxi = 1;
        if(prev==-1) {
            for(int j=i+1;j<a.size();j++) {
                maxi = max(maxi, 1+func(j, i, a));
            }
        }
        else {
            int next = a[i] + a[i]-a[prev];
            if(!mp.count(next)) return 1;
            int pos = lower_bound(mp[next].begin(), mp[next].end(), i+1) - mp[next].begin();
            if(pos==mp[next].size()) return 1;
            maxi = max(maxi, 1+func(mp[next][pos],i, a)) ;
        }
        return dp[i][prev+1] = maxi;
    }
    int longestArithSeqLength(vector<int>& a) {
        for(int i=0;i<a.size();i++) {
            mp[a[i]].push_back(i);
        }
        memset(dp,-1,sizeof(dp));
        int ans = 1;
        for(int i=0;i<a.size();i++) {
            ans = max(ans, func(i, -1, a));
        }
        return ans;
    }
};