class Solution {
public:
    vector<vector<int>>dp;
    int ans = INT_MAX;
    int func(int i,int x,int y, vector<int>&a, int sum) {
        int diff = abs(x-y);
        if(i>=a.size()) {
            return abs(x-y);
        }
        if(dp[i][diff]!=-1) return dp[i][diff];
        return dp[i][diff] = min(func(i+1,x+a[i],y,a,sum),func(i+1,x,y+a[i],a,sum));
    }
    int lastStoneWeightII(vector<int>& a) {
        int sum = 0;
        for(auto x:a) sum+=x;
        dp.resize(a.size(),vector<int>(sum,-1));
        return func(0,0,0,a,sum);
    }
};