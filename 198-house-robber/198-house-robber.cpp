class Solution {
public:
    // int ans = 0;
    vector<int>dp;
    int func(int pre, int cur, vector<int>&a) {
        if(cur>a.size()-1) {
            return 0;
        }
        if(dp[cur]!=-1) return dp[cur];
        int ans = 0;
        if(cur-pre>1) {
            ans = max(a[cur] + func(cur,cur+2,a),func(pre,cur+1,a));
        }
        return dp[cur] = ans;
    }
    int rob(vector<int>& a) {
        dp.resize(a.size()+1,-1);
        return func(-2,0,a);
        // return ans;
    }
};