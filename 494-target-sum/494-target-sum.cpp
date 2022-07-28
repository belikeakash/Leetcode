class Solution {
public:
    vector<vector<int>>dp;
    int func(int i, vector<int>&a, int x, int sum) {
        if(sum>x) return 0;
        if(i==a.size()) {
            if(sum==x) return 1;
            else return 0;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum] = func(i+1,a,x,sum+a[i]) + func(i+1,a,x,sum);
    }
    int findTargetSumWays(vector<int>& a, int target) {
        int sum = 0;
        for(auto x:a) sum+=x;
        int x = sum-target;
        cout<<x<<" ";
        if(x%2!=0 || x<0) return 0;
        dp.resize(a.size()+1,vector<int>(x+1,-1));
        return func(0,a,x/2,0);
        // return ans;
    }
};