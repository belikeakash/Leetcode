class Solution {
public:
    vector<vector<int>>dp;
    int func(int pre, int cur, vector<int>&a) {
        if(cur==a.size()) return 0;
        if(dp[pre+1][cur+1]!=-1) return dp[pre+1][cur+1];
        if(pre==-1 || a[cur]>a[pre]) {
            return dp[pre+1][cur+1] = max(1 + func(cur,cur+1,a), func(pre,cur+1,a)) ;
        }
        else {
            return dp[pre+1][cur+1] = func(pre,cur+1,a);
        }
    }
    int lengthOfLIS(vector<int>& a) {
        dp.resize(a.size()+1,vector<int>(a.size()+1,-1));
        return func(-1,0,a);
    }
};