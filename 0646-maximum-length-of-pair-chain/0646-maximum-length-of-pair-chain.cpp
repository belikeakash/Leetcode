class Solution {
    vector<vector<int>>dp;
public:
    int func(int prev, int i, vector<vector<int>>&a) {
        if(i>=a.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        if(prev==-1) {
            return dp[i][prev+1] = max(1+func(i, i+1, a), func(-1, i+1, a));
        }
        if(a[i][0]>a[prev][1]) return dp[i][prev+1] = max( 1 + func(i, i+1, a), func(prev, i+1, a));
        else return dp[i][prev+1] = func(prev, i+1, a);
    }
    int findLongestChain(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return func(-1, 0, a);
    }
};